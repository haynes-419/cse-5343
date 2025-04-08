package ast;

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Program extends ASTNode {

    public final String funName; // function name
    public final int retType; // function return type
    public final List<Decl> dList; // list of declarations
    public final List<Stmt> sList; // list of statements
    public final List<CFGNode> cfg; // list of CFG nodes
    private CFGNode currentNode; // current CFG node
    private int edges; // number of edges in the CFG
    private List<String> labesToAdd;
    private List<Map.Entry<CFGNode, CFGNode>> retreatingEdgeList;
    private List<CFGNode> naturalLoopList;

    public Program(String i, int t, List<Decl> dl, List<Stmt> sl) {
        funName = i;
        retType = t;
        dList = dl;
        sList = sl;
        cfg = new ArrayList<>();
        edges = 0;
        currentNode = null;
        labesToAdd = new ArrayList<>();
        retreatingEdgeList = new ArrayList<>();
        naturalLoopList = new ArrayList<>();
    }

    public void print(PrintStream ps) {
        ps.println(Types.toString(retType) + " " + funName + "()\n{");
        for (Decl d : dList) {
            d.print(ps);
        }
        for (Stmt s : sList) {
            s.print(ps, "  ");
        }
        ps.println("}");
    }

    public void cfgAnalysis() {
        //Create Entry and Exit Node
        CFGNode entry = new CFGNode();
        CFGNode exit = new CFGNode();
        currentNode = entry;
        
        cfg.add(entry);

        int i = 0;
        boolean jumpFlag = false;
        
        //Add Nodes to CFG
        while(i < sList.size()) {
            jumpFlag = digestStmt(jumpFlag, sList.get(i), i);

            //Add if not on Label
            if(!(sList.get(i) instanceof Label label)) {
                currentNode.statements.add(sList.get(i));
            }else if(cfg.size() > 1 && !(sList.get(i + 1) instanceof Label)) {
                currentNode.labelID.add(label.id);

                if(!labesToAdd.isEmpty()) {
                    for (String labelID : labesToAdd) {
                        currentNode.labelID.add(labelID);
                    }
                    labesToAdd.clear();
                }
            }
            
            i++;
        }

        //Add Exit Node
        cfg.add(exit);


       //Add Edges
        i = 0;

        while(i < cfg.size()) {
            CFGNode node = cfg.get(i);

            if(!node.gotoID.isEmpty()) {
                //Find the node with the label
                CFGNode labelNode = null;
                for (CFGNode n : cfg) {
                    for (String label : node.gotoID) {
                        if (n.labelID.contains(label)) {
                            labelNode = n;
                            break;
                        }
                    }
                }

                //Add Edge
                if(labelNode != null) {
                    node.successors.add(labelNode);
                    labelNode.predecessors.add(node);
                }

                //Add Edge to Following Node if Node.Stmts contains IfStmt
                if(node.statements.get(node.statements.size() - 1) instanceof IfStmt) {
                    if(i + 1 < cfg.size()) {
                        CFGNode nextNode = cfg.get(i + 1);
                        node.successors.add(nextNode);
                        nextNode.predecessors.add(node);
                    }
                }
                
            }else{
                //Add Edge to next node
                if(i + 1 < cfg.size()) {
                    CFGNode nextNode = cfg.get(i + 1);
                    node.successors.add(nextNode);
                    nextNode.predecessors.add(node);
                }
            }
            i++;
        }

        //Depth First Search of CFG For Back Edges
        DFS(entry);

        //Depth First Search For Natural Loops
        for(Map.Entry edgePair : retreatingEdgeList){
            reverseDFS(edgePair);
        }
        
        
        

        printData();
    }

    private boolean digestStmt(boolean jumpFlag, Stmt s, int index) {
        //System.out.println("Stmt: " + s.getClass().getName());
            // if(s instanceof Label label) {
            //     System.out.println("Hit Label: " + label.id);
            // }


        if (s instanceof Label|| jumpFlag || cfg.size() == 1) {
            if(sList.size() > index + 1 && s instanceof Label && sList.get(index + 1) instanceof Label) {
                labesToAdd.add( ((Label) sList.get(index)).id);
                return jumpFlag;
            }

            CFGNode newNode = new CFGNode();
            currentNode = newNode;

            cfg.add(newNode);
            jumpFlag = false;
        }else if(s instanceof GotoStmt gotoStmt) {
            //Flip Jump Flag
            currentNode.gotoID.add(gotoStmt.id);
            jumpFlag = true;
        }

        if(s instanceof IfStmt ifStmt) {
            jumpFlag = digestStmt(jumpFlag, ifStmt.thenStmt, index);
        }
        

        return jumpFlag;
    }

    private void DFS(CFGNode node) {
        node.color = "gray";

        for (CFGNode m : node.successors) {
            if(m.color.equals("white")) {
                DFS(m);
            }else if(m.color.equals("gray")) {
                retreatingEdgeList.add(Map.entry(node, m));
            }
        }

        node.color = "black";
    }

    private void reverseDFS(Map.Entry<CFGNode, CFGNode> nodePair) {
        CFGNode n = nodePair.getKey();
        CFGNode h = nodePair.getValue();

        h.colorNatualLoop = "gray";

        naturalLoopList.add(h);
        DFSNaturalLoop(n);
    }

    private void DFSNaturalLoop(CFGNode node) {
        node.colorNatualLoop = "gray";

        for (CFGNode m : node.successors) {
            if(m.colorNatualLoop.equals("white")) {
                DFSNaturalLoop(m);
            }else if(m.colorNatualLoop.equals("gray")) {
                naturalLoopList.add(m);
            }
        }

        node.colorNatualLoop = "black";
    }






    private void printData() {
        //Print CFG Nodes
        // for (int j = 0; j < cfg.size(); j++) {
        //     CFGNode node = cfg.get(j);
        //     System.out.println("Node " + j + ": " + node);
        //     System.out.println("Label: " + node.labelID);
        //     System.out.println("Goto: " + node.gotoID);
        //     for (Stmt s : node.statements) {
        //         System.out.println(s.getClass().getName());
        //     }
        //     System.out.println("Successors: " + node.successors);
        //     System.out.println("Predecessors: " + node.predecessors);
        //     System.out.println();
        // }

        //Calculate Edges
        for (CFGNode node : cfg) {
            edges += node.successors.size();
        }

        //Print Proper Output
        System.out.println("CFG NODES: " + cfg.size());
        System.out.println("CFG EDGES: " + edges);
        System.out.println("BACK EDGES: " + retreatingEdgeList.size());
        System.out.println("NODES IN LOOPS: " + naturalLoopList.size());
    }
}

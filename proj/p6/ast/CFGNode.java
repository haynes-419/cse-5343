package ast;

import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

public class CFGNode {
    public String color;
    public String colorNatualLoop;
    public Set<String> labelID;
    public Set<String> gotoID;
    public Set<CFGNode> successors;
    public Set<CFGNode> predecessors;
    public List<Stmt> statements;

    public CFGNode() {
        this.color = "white";
        this.colorNatualLoop = "white";
        this.labelID = new LinkedHashSet<>();
        this.gotoID = new LinkedHashSet<>();
        this.successors = new LinkedHashSet<>();
        this.predecessors = new LinkedHashSet<>();
        this.statements = new LinkedList<>();
    }
}

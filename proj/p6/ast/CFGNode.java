package ast;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

public class CFGNode {
    public Set<String> labelID;
    public Set<String> gotoID;
    public Set<CFGNode> successors;
    public Set<CFGNode> predecessors;
    public List<Stmt> statements;

    public CFGNode() {
        this.labelID = new HashSet<>();
        this.gotoID = new HashSet<>();
        this.successors = new HashSet<>();
        this.predecessors = new HashSet<>();
        this.statements = new LinkedList<>();
    }
}

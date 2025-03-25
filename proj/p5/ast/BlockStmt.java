package ast;
import java.io.PrintStream;
import java.util.List;

public class BlockStmt extends Stmt {
    public final List<Stmt> sList;
    public BlockStmt(List<Stmt> sl) {
	sList = sl;
    }

    @Override
    public void print(PrintStream ps, String space) { 
	ps.println(space + "{");
	for (Stmt s : sList) 
	    s.print(ps, space + "  ");	 
	ps.println(space + "}");
    }

    @Override
    public void check() {
        for (Stmt s : sList) {
            s.check();
        }
    }

    @Override
    public void genCode(){
        for (Stmt s : sList) 
            s.genCode();	 
    }
}


package ast;
import java.io.PrintStream;

public class GotoStmt extends Stmt {
    public final String id; 
    public GotoStmt(String i) {
        id = i;
    }

    public void print(PrintStream ps, String space) {
        ps.print(space + "goto ");
        ps.print(id);
        ps.println(" ;");
    }
}

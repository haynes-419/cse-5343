package ast;
import java.io.PrintStream;

public class WhileStmt extends Stmt {
    public final Expr expr;
    public final Stmt stmt;

    public WhileStmt(Expr e, Stmt s){
        expr = e;
        stmt = s;
    }

    public void print(PrintStream ps, String space) {
        ps.print(space + "while (");
        expr.print(ps);
        ps.println(")");

        stmt.print(ps, space + " ");
    }
}

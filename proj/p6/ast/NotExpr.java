package ast;
import java.io.PrintStream;

public class NotExpr extends Expr {
    public final Expr expr;
    public NotExpr(Expr e) {
        expr = e;
    }


    public void print(PrintStream ps) {
        ps.print("!(");
        expr.print(ps);
        ps.print(")");
    }
}

package ast;
import java.io.PrintStream;

public class ReturnStmt extends Stmt {
    public final Expr expr;
    public int type;
    public ReturnStmt(Expr e) {
	expr = e;
    }

    @Override
    public void print(PrintStream ps, String space) { 
	ps.print(space + "return ");
	expr.print(ps);
	ps.println(";");
    }

    @Override
    public void check() {
        expr.check();
        type = expr.type;
    }
}

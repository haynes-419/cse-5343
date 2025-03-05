package ast;
import java.io.PrintStream;

public class ExprStmt extends Stmt {
    public final Expr expr;
    public ExprStmt(Expr e) {
	expr = e;
    }

    @Override
    public void print(PrintStream ps, String space) { 
	ps.print(space);
	expr.print(ps);
	ps.println(";");
    }

    @Override
    public void check() {
        expr.check();
    }

    @Override
    public void genCode() {
        expr.genCode();
    }
}

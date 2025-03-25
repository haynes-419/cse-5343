package ast;
import java.io.PrintStream;

public class IntConstExpr extends Expr {
    public final Integer ival; 
    public IntConstExpr(Integer i) {
	ival = i;
    type = 1;
    }

    @Override
    public void print(PrintStream ps) {
	ps.print(ival);
    }

    @Override
    public void check() {
    }

    @Override
    public void genCode() {
        value = Integer.toString(ival);
    }
}

package ast;
import java.io.PrintStream;

public class DoubleConstExpr extends Expr {
    public final Double dval; 
    public DoubleConstExpr(Double d) {
	dval = d;
    type = 2;
    }

    @Override
    public void print(PrintStream ps) {
	ps.print(dval);
    }

    @Override
    public void check() {

    }

    @Override
    public void genCode() {
        value = Double.toString(dval);
    }
}

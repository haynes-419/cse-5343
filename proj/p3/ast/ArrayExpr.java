package ast;
import java.io.PrintStream;
import java.util.List;

public class ArrayExpr extends Expr {
    public final String id; 
    public final List<Expr> dims;
    public ArrayExpr(String i, List<Expr> d) {
	id = i;
	dims = d;
	type = 3;
    }

    @Override
    public void print(PrintStream ps) {
	ps.print(id);
	for (Expr d : dims) {
	    ps.print("["); 
	    d.print(ps);
	    ps.print("]");
	}
    }

    @Override
	public void check() {
		//Set Array Type
		compiler.Compiler.setSymbolTableVariableType(this);

		//Check Array Bounds - Add Symbol Table Values
		compiler.Compiler.checkArrayAttributes(this);
	}
}

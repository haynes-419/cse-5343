package ast;
import java.io.PrintStream;

public class IdentExpr extends Expr {
    public final String id; 
    public IdentExpr(String i) {
	id = i;
    type = 3;
    }

    @Override
    public void print(PrintStream ps) {
	ps.print(id);
    }

    @Override
    public void check() {
        compiler.Compiler.setSymbolTableVariableType(this);
    }
}

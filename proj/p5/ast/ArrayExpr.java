package ast;
import java.io.PrintStream;
import java.util.LinkedList;
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
		//Check Symbol is in Table
        if(!Program.symbolTable.containsKey(id)){
            compiler.Compiler.fatalError("Variable Not Declared", compiler.Compiler.EXIT_SEMANTIC_CHECKING_ERROR);
        }

		//Set Array Type
		compiler.Compiler.setSymbolTableVariableType(this);

		//Check Array Bounds - Add Symbol Table Values
		compiler.Compiler.checkArrayAttributes(this);
	}

	@Override
    public void genCode() {
		List<String> dimList = new LinkedList<>();
		for (Expr d : dims) {
			d.genCode();
			dimList.add("[" + d.value + "]");
		}
	
		value = id;
		for(int i = 0; i < dims.size(); i++){
			value += (dimList.get(i));
		}
    }
}

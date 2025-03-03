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
        //Check Symbol is in Table
        if(!Program.symbolTable.containsKey(id)){
            compiler.Compiler.fatalError("Variable Not Declared", compiler.Compiler.EXIT_SEMANTIC_CHECKING_ERROR);
        }

        compiler.Compiler.setSymbolTableVariableType(this);
    }
}

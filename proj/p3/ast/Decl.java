package ast;
import java.io.PrintStream;
import java.util.List;

import compiler.Compiler;

public class Decl extends ASTNode {
    public final String id; 
    public final int type;
    public final List<Integer> dims; // empty for scalars
    public Decl(String i, int t, List<Integer> d) {
	id = i;
	type = t;
	dims = d;
    }
    public boolean isScalar() { return dims.size() == 0; }
    public void print(PrintStream ps) { 
	ps.print("  " + Types.toString(type) + " " + id);
	if (isScalar()) { 	
	    ps.println(";");
	    return;
	}
	// array type
	for (Integer i : dims) {
	    ps.print("[");
	    ps.print(i);
	    ps.print("]");
	}
	ps.println(";");
    }

	public void check() {
		if(Program.symbolTable.containsKey(id)){
			//Output Duplicate Variable Error
			Compiler.fatalError("Duplicate Variable Declaration", Compiler.EXIT_PARSING_ERROR);
		}else{
			//Check Dimensions of Array
			if(!dims.isEmpty()){
				for(Integer dim : dims){
					if(dim < 1){
						Compiler.fatalError("Array Dimension Less Than 0", Compiler.EXIT_PARSING_ERROR);
					}
				}
			}

			//Add Symbol To Table
			Program.symbolTable.put(id, this);
		}
	}
}

package ast;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Program extends ASTNode {
    public final String funName; // function name
    public final int retType; // function return type
    public final List<Decl> dList; // list of declarations
    public final List<Stmt> sList; // list of statements
    public static Map<String, Decl> symbolTable;
    public static int tempVarIndex;
    public Program(String i, int t, List<Decl> dl, List<Stmt> sl) {
	funName = i;
	retType = t;
	dList = dl;
    sList = sl;
    tempVarIndex = 1;
    }
    public void print(PrintStream ps) {
	ps.println(Types.toString(retType) + " " + funName + "()\n{");
	for (Decl d : symbolTable.values()) 
	    d.print(ps);
	for (Stmt s : sList) 
	    s.print(ps,"  ");
	ps.println("}");
    }

    public void check() {
        symbolTable = new HashMap<>();
        
        //Check Declarations
        for (Decl d : dList) {
            d.check();
        }

        for (Stmt s : sList) {
	        s.check();

            //Check Return Type
            if(s instanceof ReturnStmt returnStmt){
                if(retType != returnStmt.type && (retType == Types.INT && returnStmt.type == Types.DOUBLE) ){
                    compiler.Compiler.fatalError("Return Type Does not Match", compiler.Compiler.EXIT_SEMANTIC_CHECKING_ERROR);
                }
            }
        }

        System.out.println("Symbol Table: " + symbolTable.toString());
    }
}

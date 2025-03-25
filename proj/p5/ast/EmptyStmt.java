package ast;
import java.io.PrintStream;

public class EmptyStmt extends Stmt {
    @Override
    public void print(PrintStream ps, String space) { 
	ps.println(space + ";");
    }

    @Override
    public void check() {
    }

    @Override
    public void genCode(){
        
    }
}

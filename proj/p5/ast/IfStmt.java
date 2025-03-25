package ast;
import java.io.PrintStream;

public class IfStmt extends Stmt {
    public final Expr expr;
    public final Stmt thenStmt;
    public final Stmt elseStmt; // null for if-then
    public IfStmt(Expr e, Stmt ts) {
	expr = e;
	thenStmt = ts;
	elseStmt = null;
    }
    public IfStmt(Expr e, Stmt ts, Stmt es) {
	expr = e;
	thenStmt = ts;
	elseStmt = es;
    }

    @Override
    public void print(PrintStream ps, String space) { 
	ps.print(space + "if (");
	expr.print(ps);
	ps.println(")");
        thenStmt.print(ps, space + "  ");	 
	if (elseStmt != null) {
	    ps.println(space + "else");
	    elseStmt.print(ps, space + "  ");	 
	}
    }

    @Override
	public void check() {
		expr.check();
		thenStmt.check();

		if (elseStmt != null) {
			elseStmt.check();	 
		}
	}

	@Override
	public void genCode() {
		expr.genCode();
		
		String exitLabel = "_l" + Program.jumpVarIndex++;
		String elseLabel;

		if(elseStmt != null){
			elseLabel = "_l" + Program.jumpVarIndex++;
			System.out.println("if (!" + expr.value + ") goto " + elseLabel + ";");
			thenStmt.genCode();

			System.out.println("goto " + exitLabel + ";");
			System.out.println(elseLabel + ":");
			elseStmt.genCode();
			System.out.println(exitLabel + ":");
		}else{
			System.out.println("if (!" + expr.value + ") goto " + exitLabel + ";");
			thenStmt.genCode();
			System.out.println(exitLabel + ":");
		}
	}
}

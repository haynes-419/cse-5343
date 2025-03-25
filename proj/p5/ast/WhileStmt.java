package ast;
import java.io.PrintStream;

public class WhileStmt extends Stmt {
    public final Expr expr;
    public final Stmt stmt;

    public WhileStmt(Expr e, Stmt s){
        expr = e;
        stmt = s;
    }

    @Override
    public void print(PrintStream ps, String space) {
        ps.print(space + "while (");
        expr.print(ps);
        ps.println(")");

        stmt.print(ps, space + " ");
    }

    @Override
    public void check(){
        expr.check();
        stmt.check();
    }

    @Override
    public void genCode() {
        String startLabel = "_l" + Program.jumpVarIndex++;
        String exitLabel = "_l" + Program.jumpVarIndex++;

        System.out.println(startLabel + ":");
        expr.genCode();
        System.out.println("if (! " + expr.value + ") goto " + exitLabel + ";");
        stmt.genCode();
        System.out.println("goto " + startLabel + ";");
        System.out.println(exitLabel + ":");
    }
}

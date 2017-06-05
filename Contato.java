package exercicio2;
import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.ArrayList;
import java.util.Calendar;

public interface Contato extends Remote {
	
    boolean Cadastrar(ContatoClass C) throws RemoteException;
    String ListarContatos() throws RemoteException;
    public ArrayList<ContatoClass> Buscar(String nome) throws RemoteException;
    void LimparLista() throws RemoteException;
    void Find_and_Remove(String tel) throws RemoteException;
    boolean Atualizar_Telfone(String nome, String tele_novo) throws RemoteException;
    
    
    
    
}
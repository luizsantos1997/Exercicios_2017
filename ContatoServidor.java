package exercicio2;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Iterator;



public class ContatoServidor implements Contato {

    
	
        ArrayList<ContatoClass> C_Lista = new ArrayList<ContatoClass>();
  
	public static void main(String args[]) {

		try {
			ContatoServidor objServ = new ContatoServidor();
			//Exporta obj. servidor para receber chamadas remotas
			//e retorna o obj. stub p/ ser registrado no servi�o de nomes
			Contato stubCalendar =
					(Contato) UnicastRemoteObject.exportObject(objServ, 0);

			//Registra o stub do obj. remoto no
			//servi�o de nomes RMI_REGISTRY
			Registry registry = LocateRegistry.createRegistry(1234);
			registry.rebind("Contato", stubCalendar);
			
			//A partir de ent�o o servidor fica instanciado e
			//e aguardando chamadas remotas para ele.
			System.out.println("Servidor pronto!");
		} catch (Exception e) {
			System.out.println("Server exception: " + e.toString());
			e.printStackTrace();
		}
	}
    
     

    @Override
    public boolean Cadastrar(ContatoClass C) throws RemoteException {
       for(ContatoClass x:C_Lista){
           if(C.getNome().equals(x.getNome())){
               return false;
           }
       }
       C_Lista.add(C);
       return true;
   }

    @Override
    public String ListarContatos() throws RemoteException {
        String retorno = "";
        for(ContatoClass C : C_Lista){
            retorno += "Nome: "+C.getNome() +" - Telefone: "+ C.getTel() + '\n';
        }
        return retorno;
    }

    
    @Override
    public ArrayList<ContatoClass> Buscar(String nome) throws RemoteException {
       ArrayList<ContatoClass> Lista = new ArrayList<>();
       for(ContatoClass x :C_Lista){
           if(x.getNome().contains(nome)){
           Lista.add(x);
           }
       }
       
       return Lista; 
    }

   

    @Override
    public void LimparLista() throws RemoteException {
        C_Lista.clear();
    }

    @Override
    public void Find_and_Remove(String tel) throws RemoteException {
            for (Iterator<ContatoClass> iterator = C_Lista.iterator(); iterator.hasNext();) {
            ContatoClass next = iterator.next();
            
        
            if(next.getTel().equals(tel+"")){
                iterator.remove();
            }
            }
    } 

    @Override
    public boolean Atualizar_Telfone(String nome, String tele_novo) throws RemoteException {
        for(ContatoClass X:C_Lista){
        if(X.getNome().equals(nome)){
            X.setTel(tele_novo);
            return true;
        }
        }
        return false;
    }
    
    
    }

    

    

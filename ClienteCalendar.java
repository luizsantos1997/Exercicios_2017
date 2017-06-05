package exercicio2;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.ArrayList;
import java.util.Scanner;

public class ClienteCalendar {

    public static void main(String args[]) {
        try {
            String host = null;

            Registry registry = LocateRegistry.getRegistry(host, 1234);

            Contato stubCalendar
                    = (Contato) registry.lookup("Contato");
            ArrayList<ContatoClass> retorno = null;

            Scanner leitorTeclado = new Scanner(System.in);
            String opcao = "";
            while (!opcao.equals("7")) {
                System.out.println("1 - Cadastrar; 2 - Listar; 3 - Buscar nome; 4 - Remover Contato pelo Telefone; 5 - Limpar Lista; 6 - Atualizar Telefone; 7 - Sair ");
                opcao = leitorTeclado.nextLine();
                if (opcao.equals("1")) {
                    
                    System.out.print("Nome: ");
                    String nome_contato = leitorTeclado.nextLine();
                    System.out.print("Endereço: ");
                    String endereco_contato = leitorTeclado.nextLine();
                    System.out.print("Telefone: ");
                    String telefone_contato = leitorTeclado.nextLine();
                    
                    ContatoClass contato = new ContatoClass(nome_contato,telefone_contato,endereco_contato);
                    if(stubCalendar.Cadastrar(contato)){
                        System.out.println("Contato Cadastrado com Sucesso");
                    }else{
                        System.out.println("Contato já existe na Lista!");
                    }

                } else if (opcao.equals("2")) {
                    System.out.println(stubCalendar.ListarContatos());
                } else if (opcao.equals("3")) {
                    
                    System.out.print("Nome para busca: ");
                    
                
                    retorno = stubCalendar.Buscar(leitorTeclado.nextLine());
                    System.out.println("");
                    for( ContatoClass x:retorno){
                    System.out.println(x.getNome() +" - "+x.getTel());
                }
                }else if(opcao.equals("4")){
                    System.out.print("Insira o telefone para remover: ");
                    String tel = leitorTeclado.nextLine();
                    stubCalendar.Find_and_Remove(tel);
                }else if(opcao.equals("5")){
                    stubCalendar.LimparLista();
                }else if(opcao.equals("6")){
                    String nome = leitorTeclado.nextLine();
                    String novo_tel = leitorTeclado.nextLine();
                    if(stubCalendar.Atualizar_Telfone(nome, novo_tel)){
                        System.out.println("Número Atualizado com sucesso");
                    }else{
                        System.out.println("Contato Inexistente!");
                    }
                }
    }

    


} catch (Exception e) {
			System.err.println("Client exception: " + e.toString());
			e.printStackTrace();
		}
	}

}

//EXERCICIO USANDO RMI LISTA DE CONTATO(Nome,endereço,telefone);

package exercicio2;

import java.io.Serializable;


public class ContatoClass implements Serializable {

   
    private String nome;
    private String tel;
    private String end;

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getTel() {
        return tel;
    }

    public void setTel(String tel) {
        this.tel = tel;
    }

    public String getEnd() {
        return end;
    }

    public void setEnd(String end) {
        this.end = end;
    }

    public ContatoClass(String nome,String tel,String end){
        setNome(nome);
        setEnd(end);
        setTel(tel);
    }

    
    
    
}

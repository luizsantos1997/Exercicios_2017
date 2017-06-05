/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exercicio2;

import java.io.Serializable;

/**
 *
 * @author 161052088
 */
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

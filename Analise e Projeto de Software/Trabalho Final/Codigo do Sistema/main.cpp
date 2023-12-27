#include <iostream>

class Produto{
  public:
    long id;
    int quantidade;
    std::string descricao;
    float preco;
};

class Fornecedor{
  public:
  std::string nome;
  std::string cnpj;
  std::string endereco;
  std::string email;
  bool situacao;
};

class MovimentoDeProduto{
  public:
    int quantidade;
    bool tipo;
    Produto produto;
    Fornecedor fornecedor;

    void setProduto(Produto* produto){
      this->produto = *produto;  
    }
    void setQuantidade(int quantidade){
      this->quantidade = quantidade;
    }
    void setFornecedor(Fornecedor* fornecedor){
      this->fornecedor = *fornecedor;
    }
};

class MovimentoDeProdutoDao{
  public:
    MovimentoDeProduto* create(){return new MovimentoDeProduto};
};

class ProdutoDao{
  public:
    Produto* retrieve(long* id_produto);
};

class FornecedorDao{
  public:
    Fornecedor* retrieve(std::string* CNPJ_fornecedor);
};

class DaoManager{
  public:
    MovimentoDeProdutoDao* getMovimentoDeProdutoDao();
    ProdutoDao* getProdutoDao();
    FornecedorDao* getFornecedorDao();
};

class MovimentoDeProdutoMgr{
  DaoManager* daoManager;
  MovimentoDeProduto* movimentoAtual;

  public:
    MovimentoDeProdutoMgr(DaoManager*);

    void setMovimentoAtual(MovimentoDeProduto* movimento){this->movimentoAtual = movimento;}

    MovimentoDeProduto* registrarEntrada(Produto* id_produto, Fornecedor* CNPJ_fornecedor, int produto_quantidade){
      MovimentoDeProduto* mp = this->daoManager->getMovimentoDeProdutoDao()->create();
      Produto* pdto = this->daoManager->getProdutoDao()->retrieve(id_produto);
      mp->setProduto(pdto);
      Fornecedor* f = this->daoManager->getFornecedorDao()->retrieve(CNPJ_fornecedor);
      mp->setFornecedor(f);
      mp->setQuantidade(produto_quantidade);
      this->setMovimentoAtual(mp);
    }

    MovimentoDeProduto* registrarSaida(Produto* id_produto, Fornecedor* CNPJ_fornecedor, int produto_quantidade){
      MovimentoDeProduto* mp = this->daoManager->getMovimentoDeProdutoDao()->create();
      Produto* pdto = this->daoManager->getProdutoDao()->retrieve(id_produto);
      mp->setProduto(pdto);
      mp->setQuantidade(produto_quantidade);
      this->setMovimentoAtual(mp);
    }

};

int main(){
  MovimentoDeProdutoMgr* movProdMgr = new MovimentoDeProdutoMgr(new DaoManager());

  std::cout << "registrar entrada ou saida?";
  int entrada_ou_saida;
  std::cin >> entrada_ou_saida;

  switch(entrada_ou_saida){
    case 1:
      std::cout << "registrar entrada\n";

      std::cout << "id produto:\n";
      long id_produto_entrada;
      std::cin >> id_produto_entrada;

      std::cout << "CNPJ fornecedor:\n";
      std::string CNPJ_fornecedor_entrada;
      std::cin >> CNPJ_fornecedor_entrada;

      std::cout << "quantidade:\n";
      int produto_quantidade_entrada;
      std::cin >> produto_quantidade_entrada;

      movProdMgr->registrarEntrada(id_produto_entrada, CNPJ_fornecedor_entrada,   produto_quantidade_entrada);

      std::cout << "movimento registrado\n";

      break;
    case 2:
      std::cout << "registrar saida";

      std::cout << "id produto:\n";
      long id_produto_saida;
      std::cin >> id_produto_saida;

      std::cout << "quantidade:\n";
      int produto_quantidade_saida;
      std::cin >> produto_quantidade_saida;

      movProdMgr->registrarSaida(id_produto_saida, produto_quantidade_saida);

      std::cout << "movimento registrado\n";



      break;
    default:
      std::cout << "opcao invalida";
    break;
  }


  return 0;
}

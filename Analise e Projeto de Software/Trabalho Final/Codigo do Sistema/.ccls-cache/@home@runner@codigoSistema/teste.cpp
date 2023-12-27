#include <iostream>
#include <vector>

class Produto {
public:
    int id;
    std::string nome;
    float preco;
    int quantidade;
    std::string descricao;

    Produto(int _id, const std::string& _nome, int _quantidade) 
        : id(_id), nome(_nome), quantidade(_quantidade) {
    }

    void incrementarQuantidade(int quantidade) {
        this->quantidade += quantidade;
    }

    void decrementarQuantidade(int quantidade) {
        if (quantidade <= this->quantidade) {
            this->quantidade -= quantidade;
        } else {
            std::cerr << "Erro: Quantidade insuficiente em estoque." << std::endl;
        }
    }
};

class Fornecedor {
public:
    std::string cnpj;

    Fornecedor(const std::string& _cnpj) : cnpj(_cnpj) {}
};

class MovimentoDeProduto {
public:
    int idProduto;
    std::string cnpjFornecedor;
    int quantidade;

    MovimentoDeProduto(int _idProduto, const std::string& _cnpjFornecedor, int _quantidade)
        : idProduto(_idProduto), cnpjFornecedor(_cnpjFornecedor), quantidade(_quantidade) {}
};

class ProdutoDao {
public:
    void salvarProduto(const Produto& produto) {
        std::cout << "Produto salvo: " << produto.nome << ", Quantidade: " << produto.quantidade << std::endl;
    }
};

class FornecedorDao {
public:
    void salvarFornecedor(const Fornecedor& fornecedor) {
        std::cout << "Fornecedor salvo: " << fornecedor.cnpj << std::endl;
    }
};

class MovimentoDeProdutoDao {
public:
    void salvarMovimento(const MovimentoDeProduto& movimento) {
        std::cout << "Movimento de produto salvo." << std::endl;
    }
};

class MovimentoDeProdutoMgr {
private:
    ProdutoDao produtoDao;
    MovimentoDeProdutoDao movimentoDao;
    int quantidadeProdutoExistente;  // Variável de membro para a quantidade de produto existente

public:
    MovimentoDeProdutoMgr(int _quantidadeProdutoExistente)
        : quantidadeProdutoExistente(_quantidadeProdutoExistente) {}

    void registrarEntrada(int idProduto, const std::string& cnpjFornecedor, int quantidade) {
        Produto produto(idProduto, "Açaí", quantidadeProdutoExistente);

        produto.incrementarQuantidade(quantidade);
        produtoDao.salvarProduto(produto);

        MovimentoDeProduto movimento(idProduto, cnpjFornecedor, quantidade);
        movimentoDao.salvarMovimento(movimento);

        quantidadeProdutoExistente = produto.quantidade;  // Atualiza a quantidade no final
        std::cout << "Entrada de produto registrada com sucesso." << std::endl;
    }

    void registrarSaida(int idProduto, int quantidade) {
        Produto produto(idProduto, "Açaí", quantidadeProdutoExistente);

        produto.decrementarQuantidade(quantidade);
        produtoDao.salvarProduto(produto);

        MovimentoDeProduto movimento(idProduto, "CNPJ_SAIDA", -quantidade);
        movimentoDao.salvarMovimento(movimento);

        quantidadeProdutoExistente = produto.quantidade;  // Atualiza a quantidade no final
        std::cout << "Saída de produto registrada com sucesso." << std::endl;
    }

    int getQuantidadeProdutoExistente() const {
        return quantidadeProdutoExistente;
    }
};

int main() {
    MovimentoDeProdutoMgr manager(50);  // 50 é a quantidade pré-existente
    manager.registrarEntrada(1, "10.522.878/0001-40", 10);
    manager.registrarSaida(1, 5);

    std::cout << "Quantidade de produto final: " << manager.getQuantidadeProdutoExistente() << std::endl;

    return 0;
}

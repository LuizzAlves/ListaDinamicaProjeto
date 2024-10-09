# Projeto de Lista Dinâmica

### Objetivo
Desenvolver um sistema que utiliza uma lista dinâmica para simular o armazenamento de dados como se fosse um arquivo em disco.

### Dados a serem Armazenados
O sistema gerenciará as seguintes informações:
- Nome Completo
- Endereço Residencial
- CPF (Cadastro de Pessoa Física)
- Número de Contato
- E-mail

### Funcionalidades do Menu
O programa oferece as seguintes operações:

1. **Adicionar Entrada**  
   Permite ao usuário inserir um novo registro após verificar se o CPF é único. Se o CPF já estiver cadastrado, o sistema emite um aviso.
   
2. **Excluir Entrada**  
   Remove uma entrada com base no CPF fornecido. Se o CPF não existir, o programa ignora a solicitação e segue normalmente.

3. **Alterar Entrada**  
   Solicita o CPF e, caso o CPF exista, permite que o usuário altere qualquer informação relacionada ao registro. O usuário pode pular campos que não deseja alterar.

4. **Imprimir um Registro**  
   Solicita o CPF e exibe os dados correspondentes. Se o CPF não for encontrado, uma mensagem de alerta é exibida.

5. **Imprimir Todos os Registros**  
   Exibe todos os registros cadastrados na lista.

6. **Ordenar Registros**  
   Ordena a lista com base nos nomes dos usuários.

7. **Sair**  
   Encerra o sistema.

### Observações
- A chave de pesquisa é o CPF, garantindo que dois CPFs iguais não sejam cadastrados.
- A ordenação é realizada pelo nome dos usuários.

---

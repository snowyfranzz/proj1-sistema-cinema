# Sistema Inteligente de Gestão de Assentos de Cinema
- Projeto 1 da matéria Programação de Computadores - Primeiro Semestre

O foco deste projeto é criar um sistema de gestão de assentos para um cinema, visando melhorar o conforto dos clientes na escolha do lugar. O sistema, tendendo a otimizar a escolha dos assentos perante à preferência dos clientes, deve seguir os critérios a seguir:
- Sentar-se longe de desconhecidos, sentar-se próximo aos amigos
- Ficar próximas ao centro da sala
- Evitar fileiras muito próximas à tela

# Descrição do Projeto
A sala a ser considerada para o desenvolvimento do projeto possui:
- 10 fileiras
- 8 assentos por fileira
Cada assento será representado por:
- 0 → disponível
- 1 → ocupado

Na construção desse projeto, as seguintes funcionalidades deverão ser consideradas e construídas
usando um menu contínuo com as seguintes opções:

**1 - Exibir mapa da sala:**
- Essa funcionalidade tem como objetivo exibir a sala completa (ou seja a Matriz que representa a sala). Destacando visualmente qual as fileiras mais ocupadas.
    
**2 - Vender ingresso manualmente:**
- Aqui, o usuário escolhe a fileira em que deseja sentar-se. O sistema deve validar a posição, não permitindo que assentos ocupados sejam reocupados. E garantindo o local para o cliente.
- Cancelar venda: Somente assentos ocupados devem ser cancelados. Caso contrário indicar inconsistência. Garantir também que o assento cancelado é o que o cliente pediu.
    
**3 - Sugerir melhor assento disponível:**
- O sistema deve sugerir automaticamente um assento com base em critérios:
  - Preferir assentos mais próximos do centro da sala.
  - Evitar assentos isolados entre ocupados.
  - Evitar extremos (bordas) quando possível.
- Esta análise deve também considerar quantos ingressos o cliente está comprando.

**4 - Verificar fileiras críticas:**
- Uma fileira é considerada “crítica” quando 75% ou mais dos assentos estão ocupados.
  O sistema deve:
  - Listar essas fileiras
  - Informar a quantidade de assentos livres restantes
    
**5 - Mostrar estatísticas gerais:**
- O sistema deve calcular:
  - Total de assentos ocupados e livres
  - Percentual de ocupação
  - Fileira com maior ocupação   
  - Fileira com menor ocupação
    
**6 - Encerrar**
- Finalizar o programa.

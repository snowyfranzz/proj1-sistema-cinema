- Tela 1.1: Escolha da quantidade de ingressos
```
┌──────────────────────────────────────────────────────────────────────────────┐
│       Bem vindo! | 15:33 | Sábado, 11 de Abril de 2025 | Cinemas CineC       │
├──────────────────────────────────────────────────────────────────────────────┤
│                            Próxima Sessão: 16:20                             │
│                                 Filme: Avatar                                │
│                           Assentos Disponíveis: 56                           │
├────────────────────────────────────────────────────────────┬─────────────────┤
│                         Ingressos:                         │    Carrinho:    │
│════════════════════════════════════════════════════════════│═════════════════│
│                                                            │0x..Inteira      │
│       Meia Entrada..........................R$  9,00       │0x..Meia-Entrada │
│                                                            │                 │
│       Inteira...............................R$ 18,00       │Total:           │
│                                                            │- 0 Ingressos    │
│                                                            │- R$0,00         │
│*  O cliente pode comprar no máximo 20 ingressos de uma vez.│                 │
│                                                            │                 │
├────────────────────────────────────────────────────────────┴─────────────────┤
│          Para continuar com sua compra, utilize os comandos abaixo!          │
│══════════════════════════════════════════════════════════════════════════════│
│                1. Sair do programa (Desligar)                                │
│                2. Adicionar um Ingresso (Inteira) ao carrinho.               │
│                3. Adicionar um ingresso (Meia) ao carrinho.                  │
│                4. Prosseguir para a escolha de assento.                      │
└──────────────────────────────────────────────────────────────────────────────┘
```

- Tela 1.1: Atualizada com valores exemplares
```
┌──────────────────────────────────────────────────────────────────────────────┐
│       Bem vindo! | 15:33 | Sábado, 11 de Abril de 2025 | Cinemas CineC       │
├──────────────────────────────────────────────────────────────────────────────┤
│                            Próxima Sessão: 16:20                             │
│                                 Filme: Avatar                                │
│                           Assentos Disponíveis: 56                           │
├────────────────────────────────────────────────────────────┬─────────────────┤
│                         Ingressos:                         │    Carrinho:    │
│════════════════════════════════════════════════════════════│═════════════════│
│                                                            │1x..Inteira      │
│       Meia Entrada..........................R$  9,00       │1x..Meia-Entrada │
│                                                            │                 │
│       Inteira...............................R$ 18,00       │Total:           │
│                                                            │- 2 Ingressos    │
│                                                            │- R$27,00        │
│*  O cliente pode comprar no máximo 20 ingressos de uma vez.│                 │
│                                                            │                 │
├────────────────────────────────────────────────────────────┴─────────────────┤
│          Para continuar com sua compra, utilize os comandos abaixo!          │
│══════════════════════════════════════════════════════════════════════════════│
│                1. Sair do programa (Desligar)                                │
│                2. Adicionar um Ingresso (Inteira) ao carrinho.               │
│                3. Adicionar um ingresso (Meia) ao carrinho.                  │
│                4. Prosseguir para a escolha de assento.                      │
└──────────────────────────────────────────────────────────────────────────────┘
```


- Tela 2: Escolha dos lugares
```
┌──────────────────────────────────────────────────────────────────────────────┐
│       Bem vindo! | 15:33 | Sábado, 11 de Abril de 2025 | Cinemas CineC       │
├───────────────────────┬─────────────────────┬────────────────────────────────┤
│ Assentos Disponíveis: │      Sugestão:      │       Resumo da Compra:        │
│═══════════════════════│═════════════════════│════════════════════════════════│
│     1 2 3 4 5 6 7 8   │Para 2 ingressos, os │                                │
│                       │  melhores lugares   │1x Ingresso (Inteira)..R$ 18,00 │
│ 01  0 0 0 0 0 0 1 1   │ serão os assentos:  │                                │
│ 02  0 0 1 1 0 0 0 0   │* 05-4               │1x Ingresso (Meia).....R$  9,00 │
│ 03  0 0 1 0 0 0 1 1   │* 05-5               │                                │
│ 04  0 0 0 0 0 0 0 0 * │                     │================================│
│ 05  1 1 0 0 0 0 1 0   │                     │                                │
│ 06  0 0 1 0 0 0 1 0   ├─────────────────────┤Total:.................R$ 27,00 │
│ 07  0 0 0 1 0 1 0 0   │0: Assento Disponível│                                │
│ 08  1 1 0 1 1 1 1 0 ! │1: Assento Ocupado   │                                │
│ 09  0 1 0 1 1 0 1 0   │!: Fileira Mais Cheia│                                │
│ 10  0 0 0 0 0 0 0 0   │*: Fileira Mais Vazia│                                │
├───────────────────────┴─────────────────────┴────────────────────────────────┤
│            Para escolher seu assento, utilize os comandos abaixo!            │
│══════════════════════════════════════════════════════════════════════════════│
│                                                                              │
│                   1. Cancelar Compra.                                        │
│                   2. Prosseguir para a escolha do assento.                   │
│                                                                              │
└──────────────────────────────────────────────────────────────────────────────┘
```

- Tela 2.1: Ao inserir 2 para escolher os assentos (não limpar menu superior!):
```
Insira a fileira do assento (Ingresso #1) > 5
Insira o número do assento (Ingresso #1) > 4
Insira a fileira do assento (Ingresso #2) > 5
Insira o número do assento (Ingresso #2) > 5

Os assentos escolhidos foram: 05-4, 05-5. Isso está correto? (0. Não | 1. Sim) > 
```

- Tela 3: Compra
```
┌──────────────────────────────────────────────────────────────────────────────┐
│       Bem vindo! | 15:33 | Sábado, 11 de Abril de 2025 | Cinemas CineC       │
├──────────────────────────────────────────────────────────────────────────────┤
│                                  Carrinho:                                   │
│══════════════════════════════════════════════════════════════════════════════│
│                                                                              │
│                                                                              │
│               1x Ingresso (Inteira)...................R$ 18,00               │
│                                                                              │
│               1x Ingresso (Meia)......................R$  9,00               │
│                                                                              │
│               ================================================               │
│                                                                              │
│               Total...................................R$ 27,00               │
│                                                                              │
│                                                                              │
│                                                                              │
├──────────────────────────────────────────────────────────────────────────────┤
│           Para continuar com a compra, utilize os comandos abaixo!           │
│══════════════════════════════════════════════════════════════════════════════│
│                                                                              │
│                            1. Cancelar Compra.                               │
│                            2. Verificar pagamento.                           │
│                                                                              │
└──────────────────────────────────────────────────────────────────────────────┘
```

- Tela 4: Fim
```
┌──────────────────────────────────────────────────────────────────────────────┐
│       Bem vindo! | 15:33 | Sábado, 11 de Abril de 2025 | Cinemas CineC       │
├──────────────────────────────────────────────────────────────────────────────┤
│                                                                              │
│                                                                              │
│                                                                              │
│                                                                              │
│                                                                              │
│                                                                              │
│                       Compra efetuada com sucesso!                           │
│                           Obrigado pela compra!                              │
│                                                                              │
│                                                                              │
│                                                                              │
│                                                                              │
│                                                                              │
│                                                                              │
├──────────────────────────────────────────────────────────────────────────────┤
│                                                                              │
│                                                                              │
│                   Digite qualquer tecla para contiunuar...                   │
│                                                                              │
│                                                                              │
│                                                                              │
└──────────────────────────────────────────────────────────────────────────────┘
+ system("pause") após a tela
```

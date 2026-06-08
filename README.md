# MENTORMATCH
### Sistema de recomendação e matchmaking em tempo real entre alunos e mentores

---

# SUMÁRIO

1. Introdução
2. Problema & Solução
3. Implementações
4. Demonstração

---

# 01 — INTRODUÇÃO

## A Ideia

Conectar alunos a mentores com base em:

- Área de conhecimento
- Nível de conhecimento
- Disponibilidade
- Avaliação dos mentores

---

# 02 — PROBLEMA & SOLUÇÃO

## Problema

Muitos alunos:

- Não sabem qual mentor escolher
- Demoram para encontrar ajuda
- Precisam de recomendações rápidas

## Solução

O sistema resolve isso através de:

- Recomendação automática
- Fila de atendimento
- Ranking de mentores
- Busca inteligente

---

# 03 — IMPLEMENTAÇÕES

## Features

| Funcionalidade | Estrutura de Dados | Objetivo |
|------------|----------------|----------|
| Fila de alunos aguardando mentoria | Fila (Queue) | Organizar ordem de atendimento |
| Histórico de mentorias | Pilha (Stack) | Armazenar últimas sessões |
| Lista de alunos e mentores | Lista / Lista Encadeada | Cadastro e gerenciamento |
| Ranking de mentores | Ordenação | Ordenar por nota |
| Busca de mentor | Busca Linear / Binária | Encontrar mentor rapidamente |
| Matches ativos | Lista | Armazenar conexões em andamento |
| Recomendações | Algoritmo de compatibilidade | Sugerir melhores mentores |

---

# 04 — DEMONSTRAÇÃO

## Protótipos de Interface no Terminal

---

## Telas do Sistema

**Interfaces via Terminal (macOS / Windows)**

O sistema MentorMatch opera inteiramente via interface de linha de comando (CLI), garantindo leveza, portabilidade e foco na lógica de negócio.

As quatro telas principais cobrem o ciclo completo de uso.

| # | Tela | Função Principal |
|---|-------|-----------------|
| 1 | Menu Principal | Ponto de entrada e navegação |
| 2 | Fila em Tempo Real | Monitoramento da fila de espera |
| 3 | Match Realizado | Confirmação de conexão aluno-mentor |
| 4 | Relatórios | Estatísticas e métricas do sistema |

---

# TELA 1 — MENU PRINCIPAL

### Ponto de entrada do sistema

```text
╔════════════════╗
║   MENTORMATCH  ║
╚════════════════╝

1 - Cadastrar aluno
2 - Cadastrar mentor
3 - Entrar na fila
4 - Buscar mentor
5 - Ver ranking
6 - Relatórios
7 - Sair

Escolha uma opção:
```

### Características

- Navegação por número de opção
- Interface limpa e objetiva
- Compatível com macOS e Windows

---

# TELA 2 — FILA EM TEMPO REAL

### Estrutura de Dados: Queue (Fila FIFO)

```text
╔══════════════════════════════════╗
║        FILA DE MENTORIA          ║
╚══════════════════════════════════╝

Alunos aguardando:

1. João   → Backend
2. Maria  → Frontend
3. Lucas  → Python

[Atualizando em tempo real...]

✔ Novo match encontrado!
João ↔ Carlos (Backend)
```

### Características

- Implementada com estrutura Queue (FIFO)
- Atualização dinâmica a cada ciclo
- Exibe área de conhecimento

---

# TELA 3 — MATCH REALIZADO

### Algoritmo de compatibilidade em ação

```text
╔══════════════════════════════════╗
║         MATCH REALIZADO          ║
╚══════════════════════════════════╝

Aluno          : João
Mentor         : Carlos

Área           : Backend
Compatibilidade: 92%

──────────────────────────────────

✔ Sessão iniciada com sucesso.

──────────────────────────────────
```

### Características

- Compatibilidade calculada por algoritmo de scoring
- Considera área, nível, avaliação e disponibilidade
- Sessão registrada automaticamente no histórico (Stack)

---

# TELA 4 — RELATÓRIOS

### Métricas e desempenho do sistema

```text

╔══════════════════════════════════╗
║           RELATÓRIOS             ║
╚══════════════════════════════════╝

Mentorias realizadas    : 54
Tempo médio de espera   : 3 min
Mentor mais requisitado : Ana
Melhor avaliação        : 4.9 ★

──────────────────────────────────

Ordenação atual  : QuickSort
Tempo de execução: 0.001s

──────────────────────────────────
```

### Características

- Dados ordenados via QuickSort para ranking
- Tempo de execução monitorado para análise de performance
- Histórico consultado via Pilha (Stack)

---

# FLUXO DE INTERAÇÃO

### Do cadastro ao match — jornada completa

```text
[Cadastro] → [Entrar na Fila] → [Busca de Mentor]
                                       ↓
[Relatórios] ← [Sessão Ativa] ← [Match Realizado]
```

| Etapa | Ação do Usuário | Estrutura Envolvida |
|---------|-----------------|-------------------|
| 1 | Cadastrar aluno/mentor | Lista Encadeada |
| 2 | Entrar na fila de espera | Queue (FIFO) |
| 3 | Sistema busca mentor compatível | Busca Binária |
| 4 | Match é confirmado (92%+) | Algoritmo de Scoring |
| 5 | Sessão registrada no histórico | Stack (Pilha) |
| 6 | Relatório gerado com ranking | QuickSort |

---

# CONCLUSÃO

## MENTORMATCH

### Sistema de Matchmaking Educacional via Terminal

O MentorMatch demonstra como estruturas de dados clássicas — filas, pilhas, listas e algoritmos de ordenação e busca — podem ser combinadas para resolver um problema real de forma eficiente e elegante.

| Item | Descrição |
|--------|------------|
| Interface | Terminal CLI (macOS / Windows) |
| Estruturas usadas | Queue, Stack, Lista, QuickSort, Busca Binária |
| Tempo de matching | < 1 segundo |
| Compatibilidade mínima | 70% para aceitar match |
| Plataforma | C++ |
import sqlite3

def addPlayer(name, team_cnt):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()

    cur.execute("SELECT MAX(t_id) FROM Trainer")
    max = cur.fetchall()[0][0]
    data = [
        (max + 1, name, 1, 1, team_cnt, 1, 'brock.png')
    ]
    cur.executemany("INSERT INTO Trainer VALUES(?, ?, ?, ?, ?, ?, ?)", data)
    con.commit()

def addPokemon(name, id, moves):
    con = sqlite3.connect("pokemon.db")
    cur = con.cursor()
    cur.execute("SELECT p_id FROM Pokemon WHERE p_name = '" + str(name) + "'")
    mon = cur.fetchall()[0][0]
    data = [
        (mon, 1, id, moves[0], moves[1], moves[2], moves[3])
    ]
    cur.executemany("INSERT INTO TrainerPokemon VALUES(?, ?, ?, ?, ?, ?, ?)", data)
    con.commit()


if __name__ == "__main__":
    name = input()
    team_cnt = input()
    addPlayer(name, team_cnt)
    moves = [1, 2, 3, 4]
    addPokemon("Bulbasaur", 71, moves)
    addPokemon("Pikachu", 71, moves)
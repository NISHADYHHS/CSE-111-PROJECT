CREATE TABLE IF NOT EXISTS Pokemon (
    p_id INT PRIMARY KEY,
    p_name VARCHAR(50) NOT NULL,
    P_level INT NOT NULL,
    P_item INT NOT NULL,
    p_itemIDchance INT,
    p_type1 INT NOT NULL,
    p_type2 INT NOT NULL,
    p_height DECIMAL(5, 2) NOT NULL,
    p_weight DECIMAL(5, 2) NOT NULL,
    p_ability1 INT NOT NULL,
    p_ability2 INT,
    p_hidden_ability INT,
    p_gender_ratio_mf DECIMAL(3, 2) NOT NULL,
    p_capture_rate INT NOT NULL,
    p_HP INT, 
    p_Attack INT,
    p_Defense INT,
    p_SpecialAttack INT,
    p_SpecialDefense INT,
    p_Speed INT,
    p_description TEXT,
    p_evolution_chain_id INT,
    p_image_url VARCHAR(255),
    p_moveID INT,
    p_LocationID INT
);

CREATE TABLE IF NOT EXISTS TrainerPokemon (
    p_id INT,
    P_ability INT,
    p_trainerID INT,
    p_move1ID INT,
    p_move2ID INT,
    p_move3ID INT,
    p_move4ID INT


);

CREATE TABLE IF NOT EXISTS TrainerLocation(
   tl_locationID,
   tl_trainerID

);

CREATE TABLE IF NOT EXISTS WildEncounter(
    we_pokemonName VARCHAR(20),
    we_area VARCHAR(50),
    we_level VARCHAR(50),
    we_encounterChance INT,
    we_locationID INT
);

CREATE TABLE IF NOT EXISTS Resistance(
   r_id INT,
   r_resistane INT,
   r_immune
);

CREATE TABLE IF NOT EXISTS Weakness (
    w_id INT,
    w_weakness INT
);

CREATE TABLE IF NOT EXISTS Type (
    type_id INT PRIMARY KEY,
    type_name VARCHAR(20) NOT NULL,
    type_weaknessID INT NOT NULL,
    type_resistanceID INT
);

CREATE TABLE IF NOT EXISTS Item (
    i_id INT PRIMARY KEY,
    i_name VARCHAR(50) NOT NULL,
    i_description VARCHAR(255) NOT NULL,
    i_image_url VARCHAR(255) NOT NULL,
    i_category VARCHAR(20) NOT NULL
);

CREATE TABLE IF NOT EXISTS Moves (
    m_id INT PRIMARY KEY,
    m_name VARCHAR(50) NOT NULL,
    m_type INT NOT NULL,
    m_category VARCHAR(20) NOT NULL,
    m_power INT NOT NULL,
    m_pp INT NOT NULL,
    m_accuracy VARCHAR(20) NOT NULL
);

CREATE TABLE IF NOT EXISTS MoveTable(
   mt_pokemonID INT,
   mt_moveID INT,
   mt_level INT
);

CREATE TABLE IF NOT EXISTS Trainer (
    t_id INT PRIMARY KEY,
    t_name VARCHAR(50) NOT NULL,
    t_badge_count INT,
    t_locationID INT,
    t_team_pokemon_count INT,
    t_money INT,
    t_image_url VARCHAR(255)
);

CREATE TABLE IF NOT EXISTS Location (
    l_id INT PRIMARY KEY,
    l_name VARCHAR(50) NOT NULL,
    l_description TEXT,
    l_type VARCHAR(20),
    l_image_url VARCHAR(255)
);


CREATE TABLE IF NOT EXISTS Ability (
    a_id INT PRIMARY KEY,
    a_name VARCHAR(20) NOT NULL,
    a_description VARCHAR(255) NOT NULL,
    a_image_url VARCHAR(255) NOT NULL
);








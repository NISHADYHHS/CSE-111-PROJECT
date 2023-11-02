.headers on


SELECT p_name, a_name
FROM pokemon
INNER JOIN ability ON pokemon.p_ability1 = ability.a_id
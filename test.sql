
select * from MoveTable

select * from TrainerPokemon

delete from 
delete from TrainerPokemon where p_trainerID = 1001 AND p_id = 14
SELECT p_name 
FROM Trainer 
Inner JOIN TrainerPokemon ON TrainerPokemon.p_trainerID = Trainer.t_id 
INNER JOIN Pokemon ON Pokemon.p_name = TrainerPokemon.p_id 

select * from WildEncounter

select we_area from WildEncounter where we_pokemonName = "marill" and we_locationID = 24

update WildEncounter set we_pokemonName = "Farfetchd" where we_pokemonName = "Farfetch'd"

update Pokemon set p_name = "Farfetchd" where p_name = "Farfetch'd"

select * from WildEncounter where we_pokemonName = "Farfetch'd"
delete from TrainerPokemon where p_trainerID = 1002 AND p_id = 134

select * From TrainerPokemon
INSERT INTO Trainer (t_id,t_name,t_badge_count,t_locationID,t_team_pokemon_count,t_money,t_image_url)
VALUES (1001,'Nishad2',NULL,-1,6,0,'iris.png')

DELETE FROM Trainer
WHERE t_id>= 1000;

SELECT Moves.m_name
FROM Moves
INNER JOIN MoveTable ON Moves.m_id = MoveTable.mt_moveID
INNER JOIN Pokemon ON MoveTable.mt_pokemonID = Pokemon.p_id
WHERE p_id = 4

SELECT * 
FROM Trainer

SELECT *
FROM TrainerPokemon


<script>
    function showPokemonCard(section) {
        const selector = document.getElementById(`pokemonSelector${section}`);
        const selectedPokemonId = selector.value;

        // Hide all Pokemon cards
        const allCards = document.querySelectorAll(".pokemon-card");
        allCards.forEach(card => {
            card.style.display = "none";
        });

        // Show the selected Pokemon card
        if (selectedPokemonId !== "none") {
            const selectedCard = document.getElementById(`pokemonCard${section}`);
            if (selectedCard) {
                selectedCard.style.display = "block";
                // Fetch Pokemon details via AJAX and update the card content here
                // For simplicity, the image source is left empty in this example
                // Update the 'src' attribute with the correct URL based on your data
                const pokemonNameElement = document.getElementById(`pokemonName${section}`);
                const pokemonIDElement = document.getElementById(`pokemonID${section}`);
                pokemonNameElement.innerText = `Name: ${selector.options[selector.selectedIndex].text}`;
                pokemonIDElement.innerText = `ID: ${selectedPokemonId}`;
                selectedCard.querySelector(".pokemon-image").src = `https://raw.githubusercontent.com/PokeAPI/sprites/ceff190a63a58c266a2d8bc10525f56a83ff3992/sprites/pokemon/other/showdown/${selectedPokemonId}.gif`;
                activatePythonScript(selectedPokemonId);
            }
        }
    }

    function activatePythonScript(selectedPokemonId) {
    const xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function () {
        if (xhr.readyState === XMLHttpRequest.DONE) {
            if (xhr.status === 200) {
                const response = JSON.parse(xhr.responseText);
                console.log(response.message);
                console.log(response.result);

                // Update the Move 1 dropdown menu with the obtained result
                updateMove1Dropdown(response.result);

                // Update the page or perform other actions based on the result
                // For example, you can update a status message on the page
                const statusElement = document.getElementById('statusMessage');
                if (statusElement) {
                    statusElement.innerText = response.message;
                }
            } else {
                console.error('Error:', xhr.status);
            }
        }
    };
    xhr.open('GET', `/activate_moves/${selectedPokemonId}/`, true);
    xhr.send();
}
</script>



<label for="itemSelect">Item:</label>
            <select id="itemSelect" class="stat-input" onchange="updateTextBox('itemSelect', 'itemTextBox')">
                {% for value in items %}
                    <option value="{{ value }}" {% if value == pokemon.p_item %}selected{% endif %}>{{ value }}</option>
                {% endfor %}
            </select>
            <input type="text" id="itemTextBox" class="stat-input" readonly>
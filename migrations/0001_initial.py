# Generated by Django 4.2.7 on 2023-11-28 00:58

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Ability',
            fields=[
                ('a_id', models.AutoField(primary_key=True, serialize=False)),
                ('a_name', models.CharField(max_length=255)),
                ('a_description', models.TextField(blank=True, null=True)),
                ('a_effect', models.CharField(blank=True, max_length=255, null=True)),
                ('a_hidden', models.BooleanField(blank=True, null=True)),
                ('a_image_url', models.CharField(blank=True, max_length=255, null=True)),
            ],
            options={
                'db_table': 'Ability',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='AuthGroup',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=150, unique=True)),
            ],
            options={
                'db_table': 'auth_group',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='AuthGroupPermissions',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
            ],
            options={
                'db_table': 'auth_group_permissions',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='AuthPermission',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('codename', models.CharField(max_length=100)),
                ('name', models.CharField(max_length=255)),
            ],
            options={
                'db_table': 'auth_permission',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='AuthUser',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('password', models.CharField(max_length=128)),
                ('last_login', models.DateTimeField(blank=True, null=True)),
                ('is_superuser', models.BooleanField()),
                ('username', models.CharField(max_length=150, unique=True)),
                ('last_name', models.CharField(max_length=150)),
                ('email', models.CharField(max_length=254)),
                ('is_staff', models.BooleanField()),
                ('is_active', models.BooleanField()),
                ('date_joined', models.DateTimeField()),
                ('first_name', models.CharField(max_length=150)),
            ],
            options={
                'db_table': 'auth_user',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='AuthUserGroups',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
            ],
            options={
                'db_table': 'auth_user_groups',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='AuthUserUserPermissions',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
            ],
            options={
                'db_table': 'auth_user_user_permissions',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='DjangoAdminLog',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('object_id', models.TextField(blank=True, null=True)),
                ('object_repr', models.CharField(max_length=200)),
                ('action_flag', models.PositiveSmallIntegerField()),
                ('change_message', models.TextField()),
                ('action_time', models.DateTimeField()),
            ],
            options={
                'db_table': 'django_admin_log',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='DjangoContentType',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('app_label', models.CharField(max_length=100)),
                ('model', models.CharField(max_length=100)),
            ],
            options={
                'db_table': 'django_content_type',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='DjangoMigrations',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('app', models.CharField(max_length=255)),
                ('name', models.CharField(max_length=255)),
                ('applied', models.DateTimeField()),
            ],
            options={
                'db_table': 'django_migrations',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='DjangoSession',
            fields=[
                ('session_key', models.CharField(max_length=40, primary_key=True, serialize=False)),
                ('session_data', models.TextField()),
                ('expire_date', models.DateTimeField()),
            ],
            options={
                'db_table': 'django_session',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='Item',
            fields=[
                ('i_id', models.AutoField(primary_key=True, serialize=False)),
                ('i_name', models.CharField(max_length=255)),
                ('i_description', models.TextField(blank=True, null=True)),
                ('i_category', models.CharField(max_length=255)),
                ('i_effect', models.TextField(blank=True, null=True)),
                ('i_image_url', models.CharField(blank=True, max_length=255, null=True)),
            ],
            options={
                'db_table': 'Item',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='Location',
            fields=[
                ('l_id', models.AutoField(primary_key=True, serialize=False)),
                ('l_name', models.CharField(max_length=255)),
                ('l_description', models.TextField(blank=True, null=True)),
                ('l_type', models.CharField(blank=True, max_length=255, null=True)),
                ('l_image_url', models.CharField(blank=True, max_length=255, null=True)),
            ],
            options={
                'db_table': 'Location',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='Moves',
            fields=[
                ('m_id', models.AutoField(primary_key=True, serialize=False)),
                ('m_name', models.CharField(max_length=255)),
                ('m_type', models.IntegerField()),
                ('m_category', models.CharField(max_length=255)),
                ('m_power', models.IntegerField()),
                ('m_accuracy', models.IntegerField()),
                ('m_pp', models.IntegerField()),
                ('m_description', models.TextField(blank=True, null=True)),
                ('m_effect', models.CharField(blank=True, max_length=255, null=True)),
                ('m_image_url', models.CharField(blank=True, max_length=255, null=True)),
            ],
            options={
                'db_table': 'Moves',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='Movetable',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('mt_pokemonid', models.IntegerField(blank=True, db_column='mt_pokemonID', null=True)),
                ('mt_moveid', models.IntegerField(blank=True, db_column='mt_moveID', null=True)),
                ('mt_level', models.IntegerField(blank=True, null=True)),
            ],
            options={
                'db_table': 'MoveTable',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='Pokemon',
            fields=[
                ('p_id', models.AutoField(primary_key=True, serialize=False)),
                ('p_name', models.CharField(max_length=255)),
                ('p_level', models.IntegerField(db_column='P_level')),
                ('p_item', models.IntegerField(db_column='P_item')),
                ('p_itemidchance', models.IntegerField(blank=True, db_column='p_itemIDchance', null=True)),
                ('p_type1', models.IntegerField()),
                ('p_type2', models.IntegerField()),
                ('p_height', models.DecimalField(decimal_places=5, max_digits=10)),
                ('p_weight', models.DecimalField(decimal_places=5, max_digits=10)),
                ('p_ability1', models.IntegerField()),
                ('p_ability2', models.IntegerField(blank=True, null=True)),
                ('p_hidden_ability', models.IntegerField(blank=True, null=True)),
                ('p_gender_ratio_mf', models.DecimalField(decimal_places=5, max_digits=10)),
                ('p_capture_rate', models.IntegerField()),
                ('p_hp', models.IntegerField(blank=True, db_column='p_HP', null=True)),
                ('p_attack', models.IntegerField(blank=True, db_column='p_Attack', null=True)),
                ('p_defense', models.IntegerField(blank=True, db_column='p_Defense', null=True)),
                ('p_specialattack', models.IntegerField(blank=True, db_column='p_SpecialAttack', null=True)),
                ('p_specialdefense', models.IntegerField(blank=True, db_column='p_SpecialDefense', null=True)),
                ('p_speed', models.IntegerField(blank=True, db_column='p_Speed', null=True)),
                ('p_description', models.TextField(blank=True, null=True)),
                ('p_evolution_chain_id', models.IntegerField(blank=True, null=True)),
                ('p_image_url', models.CharField(blank=True, max_length=255, null=True)),
                ('p_moveid', models.IntegerField(blank=True, db_column='p_moveID', null=True)),
                ('p_locationid', models.IntegerField(blank=True, db_column='p_LocationID', null=True)),
            ],
            options={
                'db_table': 'Pokemon',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='PokemonAbility',
            fields=[
                ('a_id', models.AutoField(primary_key=True, serialize=False)),
                ('a_name', models.CharField(max_length=20)),
                ('a_description', models.CharField(max_length=255)),
                ('a_image_url', models.CharField(max_length=255)),
            ],
            options={
                'db_table': 'pokemon_ability',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='PokemonItem',
            fields=[
                ('i_id', models.AutoField(primary_key=True, serialize=False)),
                ('i_name', models.CharField(max_length=50)),
                ('i_description', models.CharField(max_length=255)),
                ('i_image_url', models.CharField(max_length=255)),
                ('i_category', models.CharField(max_length=20)),
            ],
            options={
                'db_table': 'pokemon_item',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='PokemonLocation',
            fields=[
                ('l_id', models.AutoField(primary_key=True, serialize=False)),
                ('l_name', models.CharField(max_length=50)),
                ('l_description', models.TextField()),
                ('l_type', models.CharField(max_length=20)),
                ('l_image_url', models.CharField(max_length=255)),
            ],
            options={
                'db_table': 'pokemon_location',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='PokemonMoves',
            fields=[
                ('m_id', models.AutoField(primary_key=True, serialize=False)),
                ('m_name', models.CharField(max_length=50)),
                ('m_type', models.IntegerField()),
                ('m_category', models.CharField(max_length=20)),
                ('m_power', models.IntegerField()),
                ('m_pp', models.IntegerField()),
                ('m_accuracy', models.CharField(max_length=20)),
            ],
            options={
                'db_table': 'pokemon_moves',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='PokemonMovetable',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('mt_pokemonid', models.IntegerField(db_column='mt_pokemonID')),
                ('mt_moveid', models.IntegerField(db_column='mt_moveID')),
                ('mt_level', models.IntegerField()),
            ],
            options={
                'db_table': 'pokemon_movetable',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='PokemonPokemon',
            fields=[
                ('p_id', models.AutoField(primary_key=True, serialize=False)),
                ('p_name', models.CharField(max_length=50)),
                ('p_level', models.IntegerField(db_column='P_level')),
                ('p_item', models.IntegerField(db_column='P_item')),
                ('p_itemidchance', models.IntegerField(blank=True, db_column='p_itemIDchance', null=True)),
                ('p_type1', models.IntegerField()),
                ('p_type2', models.IntegerField()),
                ('p_height', models.DecimalField(decimal_places=5, max_digits=10)),
                ('p_weight', models.DecimalField(decimal_places=5, max_digits=10)),
                ('p_ability1', models.IntegerField()),
                ('p_ability2', models.IntegerField(blank=True, null=True)),
                ('p_hidden_ability', models.IntegerField(blank=True, null=True)),
                ('p_gender_ratio_mf', models.DecimalField(decimal_places=5, max_digits=10)),
                ('p_capture_rate', models.IntegerField()),
                ('p_hp', models.IntegerField(blank=True, db_column='p_HP', null=True)),
                ('p_attack', models.IntegerField(blank=True, db_column='p_Attack', null=True)),
                ('p_defense', models.IntegerField(blank=True, db_column='p_Defense', null=True)),
                ('p_specialattack', models.IntegerField(blank=True, db_column='p_SpecialAttack', null=True)),
                ('p_specialdefense', models.IntegerField(blank=True, db_column='p_SpecialDefense', null=True)),
                ('p_speed', models.IntegerField(blank=True, db_column='p_Speed', null=True)),
                ('p_description', models.TextField(blank=True, null=True)),
                ('p_evolution_chain_id', models.IntegerField(blank=True, null=True)),
                ('p_image_url', models.CharField(blank=True, max_length=255, null=True)),
                ('p_moveid', models.IntegerField(blank=True, db_column='p_moveID', null=True)),
                ('p_locationid', models.IntegerField(blank=True, db_column='p_LocationID', null=True)),
            ],
            options={
                'db_table': 'pokemon_pokemon',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='PokemonResistance',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('r_id', models.IntegerField()),
                ('r_resistance', models.IntegerField()),
                ('r_immune', models.IntegerField(blank=True, null=True)),
            ],
            options={
                'db_table': 'pokemon_resistance',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='PokemonTrainer',
            fields=[
                ('t_id', models.AutoField(primary_key=True, serialize=False)),
                ('t_name', models.CharField(max_length=50)),
                ('t_badge_count', models.IntegerField()),
                ('t_locationid', models.IntegerField(db_column='t_locationID')),
                ('t_team_pokemon_count', models.IntegerField()),
                ('t_money', models.IntegerField()),
                ('t_image_url', models.CharField(max_length=255)),
            ],
            options={
                'db_table': 'pokemon_trainer',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='PokemonTrainerlocation',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('tl_locationid', models.IntegerField(db_column='tl_locationID')),
                ('tl_trainerid', models.IntegerField(db_column='tl_trainerID')),
            ],
            options={
                'db_table': 'pokemon_trainerlocation',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='PokemonTrainerpokemon',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('p_id', models.IntegerField()),
                ('p_ability', models.IntegerField(db_column='P_ability')),
                ('p_trainerid', models.IntegerField(db_column='p_trainerID')),
                ('p_move1id', models.IntegerField(db_column='p_move1ID')),
                ('p_move2id', models.IntegerField(db_column='p_move2ID')),
                ('p_move3id', models.IntegerField(db_column='p_move3ID')),
                ('p_move4id', models.IntegerField(db_column='p_move4ID')),
            ],
            options={
                'db_table': 'pokemon_trainerpokemon',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='PokemonType',
            fields=[
                ('type_id', models.AutoField(primary_key=True, serialize=False)),
                ('type_name', models.CharField(max_length=20)),
                ('type_weaknessid', models.IntegerField(db_column='type_weaknessID')),
                ('type_resistanceid', models.IntegerField(blank=True, db_column='type_resistanceID', null=True)),
            ],
            options={
                'db_table': 'pokemon_type',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='PokemonWeakness',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('w_id', models.IntegerField()),
                ('w_weakness', models.IntegerField()),
            ],
            options={
                'db_table': 'pokemon_weakness',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='PokemonWildencounter',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('we_pokemonname', models.CharField(db_column='we_pokemonName', max_length=20)),
                ('we_area', models.CharField(max_length=50)),
                ('we_level', models.CharField(max_length=50)),
                ('we_encounterchance', models.IntegerField(db_column='we_encounterChance')),
                ('we_locationid', models.IntegerField(db_column='we_locationID')),
            ],
            options={
                'db_table': 'pokemon_wildencounter',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='Resistance',
            fields=[
                ('r_id', models.AutoField(primary_key=True, serialize=False)),
                ('r_fire', models.IntegerField(blank=True, null=True)),
                ('r_water', models.IntegerField(blank=True, null=True)),
                ('r_grass', models.IntegerField(blank=True, null=True)),
                ('r_electric', models.IntegerField(blank=True, null=True)),
                ('r_ice', models.IntegerField(blank=True, null=True)),
                ('r_normal', models.IntegerField(blank=True, null=True)),
                ('r_fighting', models.IntegerField(blank=True, null=True)),
                ('r_poison', models.IntegerField(blank=True, null=True)),
                ('r_ground', models.IntegerField(blank=True, null=True)),
                ('r_flying', models.IntegerField(blank=True, null=True)),
                ('r_bug', models.IntegerField(blank=True, null=True)),
                ('r_rock', models.IntegerField(blank=True, null=True)),
                ('r_ghost', models.IntegerField(blank=True, null=True)),
                ('r_steel', models.IntegerField(blank=True, null=True)),
                ('r_psychic', models.IntegerField(blank=True, null=True)),
                ('r_dragon', models.IntegerField(blank=True, null=True)),
                ('r_dark', models.IntegerField(blank=True, null=True)),
            ],
            options={
                'db_table': 'Resistance',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='Trainer',
            fields=[
                ('t_id', models.AutoField(primary_key=True, serialize=False)),
                ('t_name', models.CharField(max_length=255)),
                ('t_badge_count', models.IntegerField(blank=True, null=True)),
                ('t_locationid', models.IntegerField(blank=True, db_column='t_locationID', null=True)),
                ('t_team_pokemon_count', models.IntegerField(blank=True, null=True)),
                ('t_money', models.IntegerField(blank=True, null=True)),
                ('t_image_url', models.CharField(blank=True, max_length=255, null=True)),
            ],
            options={
                'db_table': 'Trainer',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='Trainerlocation',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('tl_locationid', models.TextField(blank=True, db_column='tl_locationID', null=True)),
                ('tl_trainerid', models.TextField(blank=True, db_column='tl_trainerID', null=True)),
            ],
            options={
                'db_table': 'TrainerLocation',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='Trainerpokemon',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('p_id', models.IntegerField(blank=True, null=True)),
                ('p_ability', models.IntegerField(blank=True, db_column='P_ability', null=True)),
                ('p_trainerid', models.IntegerField(blank=True, db_column='p_trainerID', null=True)),
                ('p_move1id', models.IntegerField(blank=True, db_column='p_move1ID', null=True)),
                ('p_move2id', models.IntegerField(blank=True, db_column='p_move2ID', null=True)),
                ('p_move3id', models.IntegerField(blank=True, db_column='p_move3ID', null=True)),
                ('p_move4id', models.IntegerField(blank=True, db_column='p_move4ID', null=True)),
            ],
            options={
                'db_table': 'TrainerPokemon',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='Type',
            fields=[
                ('type_id', models.AutoField(primary_key=True, serialize=False)),
                ('type_name', models.CharField(max_length=255)),
                ('type_weaknessid', models.IntegerField(db_column='type_weaknessID')),
                ('type_resistanceid', models.IntegerField(blank=True, db_column='type_resistanceID', null=True)),
            ],
            options={
                'db_table': 'Type',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='Weakness',
            fields=[
                ('w_id', models.AutoField(primary_key=True, serialize=False)),
                ('w_normal', models.IntegerField(blank=True, null=True)),
                ('w_fire', models.IntegerField(blank=True, null=True)),
                ('w_water', models.IntegerField(blank=True, null=True)),
                ('w_grass', models.IntegerField(blank=True, null=True)),
                ('w_electric', models.IntegerField(blank=True, null=True)),
                ('w_ice', models.IntegerField(blank=True, null=True)),
                ('w_fighting', models.IntegerField(blank=True, null=True)),
                ('w_poison', models.IntegerField(blank=True, null=True)),
                ('w_ground', models.IntegerField(blank=True, null=True)),
                ('w_flying', models.IntegerField(blank=True, null=True)),
                ('w_psychic', models.IntegerField(blank=True, null=True)),
                ('w_bug', models.IntegerField(blank=True, null=True)),
                ('w_rock', models.IntegerField(blank=True, null=True)),
                ('w_ghost', models.IntegerField(blank=True, null=True)),
                ('w_steel', models.IntegerField(blank=True, null=True)),
                ('w_dragon', models.IntegerField(blank=True, null=True)),
                ('w_dark', models.IntegerField(blank=True, null=True)),
            ],
            options={
                'db_table': 'Weakness',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='Wildencounter',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('we_locationid', models.IntegerField(blank=True, db_column='we_locationID', null=True)),
                ('we_pokemonid', models.IntegerField(blank=True, db_column='we_pokemonID', null=True)),
                ('we_encounterchance', models.DecimalField(blank=True, db_column='we_encounterChance', decimal_places=5, max_digits=10, null=True)),
            ],
            options={
                'db_table': 'WildEncounter',
                'managed': False,
            },
        ),
    ]
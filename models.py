# This is an auto-generated Django model module.
# You'll have to do the following manually to clean this up:
#   * Rearrange models' order
#   * Make sure each model has one field with primary_key=True
#   * Make sure each ForeignKey and OneToOneField has `on_delete` set to the desired behavior
#   * Remove `managed = False` lines if you wish to allow Django to create, modify, and delete the table
# Feel free to rename the models, but don't rename db_table values or field names.
from django.db import models


class Ability(models.Model):
    a_id = models.AutoField(primary_key=True, blank=True)
    a_name = models.CharField(max_length=255)
    a_description = models.TextField(blank=True, null=True)
    a_effect = models.CharField(blank=True, null=True, max_length=255)
    a_hidden = models.BooleanField(blank=True, null=True)
    a_image_url = models.CharField(blank=True, null=True, max_length=255)

    class Meta:
        managed = False
        db_table = 'Ability'


class Item(models.Model):
    i_id = models.AutoField(primary_key=True, blank=True)
    i_name = models.CharField(max_length=255)
    i_description = models.TextField(blank=True, null=True)
    i_image_url = models.CharField(blank=True, null=True, max_length=255)
    i_category = models.CharField(max_length=255)
    

    class Meta:
        managed = False
        db_table = 'Item'


class Location(models.Model):
    l_id = models.AutoField(primary_key=True, blank=True)
    l_name = models.CharField(max_length=255)
    l_description = models.TextField(blank=True, null=True)
    l_type = models.CharField(blank=True, null=True, max_length=255)
    l_image_url = models.CharField(blank=True, null=True, max_length=255)

    class Meta:
        managed = False
        db_table = 'Location'


class Movetable(models.Model):
    mt_pokemonID = models.AutoField(primary_key=True, blank=True)  # Field name made lowercase.
    mt_moveid = models.IntegerField(db_column='mt_moveID', blank=True, null=True)  # Field name made lowercase.
    mt_level = models.IntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'MoveTable'


class Moves(models.Model):
    m_id = models.AutoField(primary_key=True, blank=True)
    m_name = models.CharField(max_length=255)
    m_type = models.IntegerField()
    m_category = models.CharField(max_length=255)
    m_power = models.IntegerField()
    m_accuracy = models.IntegerField()
    m_pp = models.IntegerField()

    class Meta:
        managed = False
        db_table = 'Moves'


class Pokemon(models.Model):
    p_id = models.AutoField(primary_key=True, blank=True)
    p_name = models.CharField(max_length=255)
    p_level = models.IntegerField(db_column='p_level')  # Field name made lowercase.
    p_item = models.IntegerField(db_column='p_item')  # Field name made lowercase.
    p_itemidchance = models.IntegerField(db_column='p_itemIDchance', blank=True, null=True)  # Field name made lowercase.
    p_type1 = models.IntegerField()
    p_type2 = models.IntegerField()
    p_height = models.DecimalField(max_digits=10, decimal_places=5)  # max_digits and decimal_places have been guessed, as this database handles decimal fields as float
    p_weight = models.DecimalField(max_digits=10, decimal_places=5)  # max_digits and decimal_places have been guessed, as this database handles decimal fields as float
    p_ability1 = models.IntegerField()
    p_ability2 = models.IntegerField(blank=True, null=True)
    p_hidden_ability = models.IntegerField(blank=True, null=True)
    p_gender_ratio_mf = models.DecimalField(max_digits=10, decimal_places=5)  # max_digits and decimal_places have been guessed, as this database handles decimal fields as float
    p_capture_rate = models.IntegerField()
    p_hp = models.IntegerField(db_column='p_HP', blank=True, null=True)  # Field name made lowercase.
    p_attack = models.IntegerField(db_column='p_Attack', blank=True, null=True)  # Field name made lowercase.
    p_defense = models.IntegerField(db_column='p_Defense', blank=True, null=True)  # Field name made lowercase.
    p_specialattack = models.IntegerField(db_column='p_SpecialAttack', blank=True, null=True)  # Field name made lowercase.
    p_specialdefense = models.IntegerField(db_column='p_SpecialDefense', blank=True, null=True)  # Field name made lowercase.
    p_speed = models.IntegerField(db_column='p_Speed', blank=True, null=True)  # Field name made lowercase.
    p_description = models.TextField(blank=True, null=True)
    p_evolution_chain_id = models.IntegerField(blank=True, null=True)
    p_image_url = models.CharField(blank=True, null=True, max_length=255)
    p_moveid = models.IntegerField(db_column='p_moveID', blank=True, null=True)  # Field name made lowercase.
    p_locationid = models.IntegerField(db_column='p_LocationID', blank=True, null=True)  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'Pokemon'


class Resistance(models.Model):
    r_id = models.AutoField(primary_key=True, blank=True)
    r_fire = models.IntegerField(blank=True, null=True)
    r_water = models.IntegerField(blank=True, null=True)
    r_grass = models.IntegerField(blank=True, null=True)
    r_electric = models.IntegerField(blank=True, null=True)
    r_ice = models.IntegerField(blank=True, null=True)
    r_normal = models.IntegerField(blank=True, null=True)
    r_fighting = models.IntegerField(blank=True, null=True)
    r_poison = models.IntegerField(blank=True, null=True)
    r_ground = models.IntegerField(blank=True, null=True)
    r_flying = models.IntegerField(blank=True, null=True)
    r_bug = models.IntegerField(blank=True, null=True)
    r_rock = models.IntegerField(blank=True, null=True)
    r_ghost = models.IntegerField(blank=True, null=True)
    r_steel = models.IntegerField(blank=True, null=True)
    r_psychic = models.IntegerField(blank=True, null=True)
    r_dragon = models.IntegerField(blank=True, null=True)
    r_dark = models.IntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'Resistance'


class Trainer(models.Model):
    t_id = models.AutoField(primary_key=True, blank=True)
    t_name = models.CharField(max_length=255)
    t_badge_count = models.IntegerField(blank=True, null=True)
    t_locationid = models.IntegerField(db_column='t_locationID', blank=True, null=True)  # Field name made lowercase.
    t_team_pokemon_count = models.IntegerField(blank=True, null=True)
    t_money = models.IntegerField(blank=True, null=True)
    t_image_url = models.CharField(blank=True, null=True, max_length=255)

    class Meta:
        managed = False
        db_table = 'Trainer'


class Trainerlocation(models.Model):
    tl_locationid = models.TextField(db_column='tl_locationID', blank=True, null=True)  # Field name made lowercase. This field type is a guess.
    tl_trainerid = models.TextField(db_column='tl_trainerID', blank=True, null=True)  # Field name made lowercase. This field type is a guess.

    class Meta:
        managed = False
        db_table = 'TrainerLocation'


class Trainerpokemon(models.Model):
    p_id = models.IntegerField(blank=True, null=True)
    p_ability = models.IntegerField(db_column='P_ability', blank=True, null=True)  # Field name made lowercase.
    p_trainerid = models.IntegerField(db_column='p_trainerID', blank=True, null=True)  # Field name made lowercase.
    p_move1id = models.IntegerField(db_column='p_move1ID', blank=True, null=True)  # Field name made lowercase.
    p_move2id = models.IntegerField(db_column='p_move2ID', blank=True, null=True)  # Field name made lowercase.
    p_move3id = models.IntegerField(db_column='p_move3ID', blank=True, null=True)  # Field name made lowercase.
    p_move4id = models.IntegerField(db_column='p_move4ID', blank=True, null=True)  # Field name made lowercase.
    tp_itemname = models.CharField(db_column='tp_itemName', max_length=255)  # Field name made lowercase.
    tp_level = models.IntegerField(blank=True, null=True)
    
    class Meta:
        managed = False
        db_table = 'TrainerPokemon'


class Type(models.Model):
    type_id = models.AutoField(primary_key=True, blank=True)
    type_name = models.CharField(max_length=255)
    type_weaknessid = models.IntegerField(db_column='type_weaknessID')  # Field name made lowercase.
    type_resistanceid = models.IntegerField(db_column='type_resistanceID', blank=True, null=True)  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'Type'


class Weakness(models.Model):
    w_id = models.AutoField(primary_key=True,blank=True)
    w_weakness = models.IntegerField(blank=True, null=True)
    

    class Meta:
        managed = False
        db_table = 'Weakness'


class Wildencounter(models.Model):
    we_pokemonName = models.AutoField(primary_key=True,blank=True)
    we_area = models.CharField(blank=True, null=True, max_length=255)
    we_level = models.CharField(blank=True, null=True, max_length=255)
    we_encounterChance = models.CharField(blank=True, null=True, max_length=255)
    we_locationID = models.IntegerField(blank=True, null=True)  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'WildEncounter'


class AuthGroup(models.Model):
    name = models.CharField(unique=True, max_length=150)

    class Meta:
        managed = False
        db_table = 'auth_group'


class AuthGroupPermissions(models.Model):
    group = models.ForeignKey(AuthGroup, models.DO_NOTHING)
    permission = models.ForeignKey('AuthPermission', models.DO_NOTHING)

    class Meta:
        managed = False
        db_table = 'auth_group_permissions'
        unique_together = (('group', 'permission'),)


class AuthPermission(models.Model):
    content_type = models.ForeignKey('DjangoContentType', models.DO_NOTHING)
    codename = models.CharField(max_length=100)
    name = models.CharField(max_length=255)

    class Meta:
        managed = False
        db_table = 'auth_permission'
        unique_together = (('content_type', 'codename'),)


class AuthUser(models.Model):
    password = models.CharField(max_length=128)
    last_login = models.DateTimeField(blank=True, null=True)
    is_superuser = models.BooleanField()
    username = models.CharField(unique=True, max_length=150)
    last_name = models.CharField(max_length=150)
    email = models.CharField(max_length=254)
    is_staff = models.BooleanField()
    is_active = models.BooleanField()
    date_joined = models.DateTimeField()
    first_name = models.CharField(max_length=150)

    class Meta:
        managed = False
        db_table = 'auth_user'


class AuthUserGroups(models.Model):
    user = models.ForeignKey(AuthUser, models.DO_NOTHING)
    group = models.ForeignKey(AuthGroup, models.DO_NOTHING)

    class Meta:
        managed = False
        db_table = 'auth_user_groups'
        unique_together = (('user', 'group'),)


class AuthUserUserPermissions(models.Model):
    user = models.ForeignKey(AuthUser, models.DO_NOTHING)
    permission = models.ForeignKey(AuthPermission, models.DO_NOTHING)

    class Meta:
        managed = False
        db_table = 'auth_user_user_permissions'
        unique_together = (('user', 'permission'),)


class DjangoAdminLog(models.Model):
    object_id = models.TextField(blank=True, null=True)
    object_repr = models.CharField(max_length=200)
    action_flag = models.PositiveSmallIntegerField()
    change_message = models.TextField()
    content_type = models.ForeignKey('DjangoContentType', models.DO_NOTHING, blank=True, null=True)
    user = models.ForeignKey(AuthUser, models.DO_NOTHING)
    action_time = models.DateTimeField()

    class Meta:
        managed = False
        db_table = 'django_admin_log'


class DjangoContentType(models.Model):
    app_label = models.CharField(max_length=100)
    model = models.CharField(max_length=100)

    class Meta:
        managed = False
        db_table = 'django_content_type'
        unique_together = (('app_label', 'model'),)


class DjangoMigrations(models.Model):
    app = models.CharField(max_length=255)
    name = models.CharField(max_length=255)
    applied = models.DateTimeField()

    class Meta:
        managed = False
        db_table = 'django_migrations'


class DjangoSession(models.Model):
    session_key = models.CharField(primary_key=True, max_length=40)
    session_data = models.TextField()
    expire_date = models.DateTimeField()

    class Meta:
        managed = False
        db_table = 'django_session'


class PokemonAbility(models.Model):
    a_id = models.AutoField(primary_key=True)
    a_name = models.CharField(max_length=20)
    a_description = models.CharField(max_length=255)
    a_image_url = models.CharField(max_length=255)

    class Meta:
        managed = False
        db_table = 'pokemon_ability'


class PokemonItem(models.Model):
    i_id = models.AutoField(primary_key=True)
    i_name = models.CharField(max_length=50)
    i_description = models.CharField(max_length=255)
    i_image_url = models.CharField(max_length=255)
    i_category = models.CharField(max_length=20)

    class Meta:
        managed = False
        db_table = 'pokemon_item'


class PokemonLocation(models.Model):
    l_id = models.AutoField(primary_key=True)
    l_name = models.CharField(max_length=50)
    l_description = models.TextField()
    l_type = models.CharField(max_length=20)
    l_image_url = models.CharField(max_length=255)

    class Meta:
        managed = False
        db_table = 'pokemon_location'


class PokemonMoves(models.Model):
    m_id = models.AutoField(primary_key=True)
    m_name = models.CharField(max_length=50)
    m_type = models.IntegerField()
    m_category = models.CharField(max_length=20)
    m_power = models.IntegerField()
    m_pp = models.IntegerField()
    m_accuracy = models.CharField(max_length=20)

    class Meta:
        managed = False
        db_table = 'pokemon_moves'


class PokemonMovetable(models.Model):
    mt_pokemonid = models.IntegerField(db_column='mt_pokemonID')  # Field name made lowercase.
    mt_moveid = models.IntegerField(db_column='mt_moveID')  # Field name made lowercase.
    mt_level = models.IntegerField()

    class Meta:
        managed = False
        db_table = 'pokemon_movetable'


class PokemonPokemon(models.Model):
    p_id = models.AutoField(primary_key=True)
    p_name = models.CharField(max_length=50)
    p_level = models.IntegerField(db_column='P_level')  # Field name made lowercase.
    p_item = models.IntegerField(db_column='P_item')  # Field name made lowercase.
    p_itemidchance = models.IntegerField(db_column='p_itemIDchance', blank=True, null=True)  # Field name made lowercase.
    p_type1 = models.IntegerField()
    p_type2 = models.IntegerField()
    p_height = models.DecimalField(max_digits=10, decimal_places=5)  # max_digits and decimal_places have been guessed, as this database handles decimal fields as float
    p_weight = models.DecimalField(max_digits=10, decimal_places=5)  # max_digits and decimal_places have been guessed, as this database handles decimal fields as float
    p_ability1 = models.IntegerField()
    p_ability2 = models.IntegerField(blank=True, null=True)
    p_hidden_ability = models.IntegerField(blank=True, null=True)
    p_gender_ratio_mf = models.DecimalField(max_digits=10, decimal_places=5)  # max_digits and decimal_places have been guessed, as this database handles decimal fields as float
    p_capture_rate = models.IntegerField()
    p_hp = models.IntegerField(db_column='p_HP', blank=True, null=True)  # Field name made lowercase.
    p_attack = models.IntegerField(db_column='p_Attack', blank=True, null=True)  # Field name made lowercase.
    p_defense = models.IntegerField(db_column='p_Defense', blank=True, null=True)  # Field name made lowercase.
    p_specialattack = models.IntegerField(db_column='p_SpecialAttack', blank=True, null=True)  # Field name made lowercase.
    p_specialdefense = models.IntegerField(db_column='p_SpecialDefense', blank=True, null=True)  # Field name made lowercase.
    p_speed = models.IntegerField(db_column='p_Speed', blank=True, null=True)  # Field name made lowercase.
    p_description = models.TextField(blank=True, null=True)
    p_evolution_chain_id = models.IntegerField(blank=True, null=True)
    p_image_url = models.CharField(max_length=255, blank=True, null=True)
    p_moveid = models.IntegerField(db_column='p_moveID', blank=True, null=True)  # Field name made lowercase.
    p_locationid = models.IntegerField(db_column='p_LocationID', blank=True, null=True)  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'pokemon_pokemon'


class PokemonResistance(models.Model):
    r_id = models.IntegerField()
    r_resistance = models.IntegerField()
    r_immune = models.IntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'pokemon_resistance'


class PokemonTrainer(models.Model):
    t_id = models.AutoField(primary_key=True)
    t_name = models.CharField(max_length=50)
    t_badge_count = models.IntegerField()
    t_locationid = models.IntegerField(db_column='t_locationID')  # Field name made lowercase.
    t_team_pokemon_count = models.IntegerField()
    t_money = models.IntegerField()
    t_image_url = models.CharField(max_length=255)

    class Meta:
        managed = False
        db_table = 'pokemon_trainer'


class PokemonTrainerlocation(models.Model):
    tl_locationid = models.IntegerField(db_column='tl_locationID')  # Field name made lowercase.
    tl_trainerid = models.IntegerField(db_column='tl_trainerID')  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'pokemon_trainerlocation'


class PokemonTrainerpokemon(models.Model):
    p_id = models.IntegerField()
    p_ability = models.IntegerField(db_column='P_ability')  # Field name made lowercase.
    p_trainerid = models.IntegerField(db_column='p_trainerID')  # Field name made lowercase.
    p_move1id = models.IntegerField(db_column='p_move1ID')  # Field name made lowercase.
    p_move2id = models.IntegerField(db_column='p_move2ID')  # Field name made lowercase.
    p_move3id = models.IntegerField(db_column='p_move3ID')  # Field name made lowercase.
    p_move4id = models.IntegerField(db_column='p_move4ID')  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'pokemon_trainerpokemon'


class PokemonType(models.Model):
    type_id = models.AutoField(primary_key=True)
    type_name = models.CharField(max_length=20)
    type_weaknessid = models.IntegerField(db_column='type_weaknessID')  # Field name made lowercase.
    type_resistanceid = models.IntegerField(db_column='type_resistanceID', blank=True, null=True)  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'pokemon_type'


class PokemonWeakness(models.Model):
    w_id = models.IntegerField()
    w_weakness = models.IntegerField()

    class Meta:
        managed = False
        db_table = 'pokemon_weakness'


class PokemonWildencounter(models.Model):
    we_pokemonname = models.CharField(db_column='we_pokemonName', max_length=20)  # Field name made lowercase.
    we_area = models.CharField(max_length=50)
    we_level = models.CharField(max_length=50)
    we_encounterchance = models.IntegerField(db_column='we_encounterChance')  # Field name made lowercase.
    we_locationid = models.IntegerField(db_column='we_locationID')  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'pokemon_wildencounter'

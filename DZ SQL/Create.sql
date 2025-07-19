CREATE TABLE IF NOT EXISTS  Genre(
 id SERIAL PRIMARY KEY,
 name VARCHAR(60) not NULL
);

CREATE TABLE IF NOT EXISTS Performer( 
 id SERIAL PRIMARY KEY,
 name VARCHAR(60) not NULL
);


CREATE TABLE IF NOT EXISTS Album( 
 id SERIAL PRIMARY KEY,
 name VARCHAR(60) not null,
 yearOfReliase DATE not null
);



CREATE TABLE IF NOT EXISTS Track( 
 id SERIAL PRIMARY KEY,
 duration TIME not null,
 name VARCHAR(60) not null,
 id_Album INTEGER REFERENCES Album(id)
);

CREATE TABLE IF NOT EXISTS Collection( 
 id SERIAL PRIMARY KEY,
 name VARCHAR(60) not null,
 yearOfReliase DATE not null
);

CREATE TABLE IF NOT EXISTS  GenrePerformer(
 genre_id INTEGER REFERENCES Genre(id),
 performer_id INTEGER REFERENCES Performer(id),
 CONSTRAINT gp PRIMARY KEY (genre_id, performer_id)
 
);

CREATE TABLE IF NOT EXISTS PerformerAlbum( 
performer_id INTEGER REFERENCES Performer(id),
album_id INTEGER REFERENCES Album(id),
CONSTRAINT pa PRIMARY KEY (performer_id, album_id)
);

CREATE TABLE IF NOT EXISTS TrackCollection( 
track_id INTEGER REFERENCES Track(id),
collection_id INTEGER REFERENCES Collection(id),
CONSTRAINT tc PRIMARY KEY (track_id, collection_id)
);


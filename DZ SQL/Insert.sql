
insert into performer(name) values('Алексей');
insert into performer(name) values('Келвин');
insert into performer(name) values('Антон');
insert into performer(name) values('Андрей');


insert into genre(name) values('Техно');
insert into genre(name) values('Метал');
insert into genre(name) values('Джаз');

insert into album(name, yearofreliase) values('Чёрное лето', '1993-07-12');
insert into album(name, yearofreliase) values('Удобный паровозик', '1918-01-02');
insert into album(name, yearofreliase) values('Утро', '2013-05-30');

insert into track(duration, id_album) values('00:05:23', 3);
insert into track(duration, id_album) values('00:07:30', 2);
insert into track(duration, id_album) values('00:02:12', 3);
insert into track(duration, id_album) values('00:03:59', 1);
insert into track(duration, id_album) values('00:05:35', 1);
insert into track(duration, id_album) values('00:04:12', 3);

insert into collection(name, yearofreliase) values('Новый мир' , '1920-07-04');
insert into collection(name, yearofreliase) values('Тепло' , '2001-07-04');
insert into collection(name, yearofreliase) values('Быстрота' , '2020-02-23');
insert into collection(name, yearofreliase) values('Ремонтник' , '1925-01-30');



insert into genreperformer(genre_id,performer_id) values(1 , 4);
insert into genreperformer(genre_id,performer_id) values(2 , 3);
insert into genreperformer(genre_id,performer_id) values(3 , 1);
insert into genreperformer(genre_id,performer_id) values(1 , 2);

insert into performeralbum (performer_id,album_id ) values(4 , 1);
insert into performeralbum (performer_id,album_id ) values(3 , 1);
insert into performeralbum (performer_id,album_id ) values(2 , 2);
insert into performeralbum (performer_id,album_id ) values(1 , 3);

insert into trackcollection (track_id,collection_id) values(1,4);
insert into trackcollection (track_id,collection_id) values(2,2);
insert into trackcollection (track_id,collection_id) values(3,3);
insert into trackcollection (track_id,collection_id) values(4,1);
insert into trackcollection (track_id,collection_id) values(5,1);
insert into trackcollection (track_id,collection_id) values(6,4);


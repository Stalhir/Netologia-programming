
select name, duration  from track
WHERE duration = (SELECT MAX(duration) FROM track);

select name, duration  from track
WHERE duration >= '00:03:30';

select name  from  collection
WHERE extract(year from yearofreliase) >= 2018 and extract(year from yearofreliase) <= 2020;

select name  from  performer
WHERE name NOT LIKE '% %'     
  AND name NOT LIKE ' %'      
  AND name NOT LIKE '% '      
  AND name NOT LIKE '';  

select  name from track
where name LIKE '%my%' and name like '%мой%';

SELECT g.name AS genre, COUNT(gp.performer_id) AS performer_count
FROM Genre g
LEFT JOIN GenrePerformer gp ON g.id = gp.genre_id
GROUP BY g.name
ORDER BY performer_count DESC;

SELECT COUNT(t.id) AS track_count
FROM Track t
JOIN Album a ON t.id_Album = a.id
WHERE EXTRACT(YEAR FROM a.yearOfReliase) BETWEEN 2019 AND 2020;

SELECT a.name AS album, 
       AVG(EXTRACT(EPOCH FROM t.duration)) AS avg_duration_seconds,
       AVG(EXTRACT(EPOCH FROM t.duration))/60 AS avg_duration_minutes
FROM Album a
JOIN Track t ON a.id = t.id_Album
GROUP BY a.name
ORDER BY avg_duration_seconds DESC;

SELECT p.name AS performer
FROM Performer p
WHERE p.id NOT IN (
    SELECT pa.performer_id
    FROM PerformerAlbum pa
    JOIN Album a ON pa.album_id = a.id
    WHERE EXTRACT(YEAR FROM a.yearOfReliase) = 2020
);

SELECT DISTINCT c.name AS collection_name
FROM Collection c
JOIN TrackCollection tc ON c.id = tc.collection_id
JOIN Track t ON tc.track_id = t.id
JOIN Album a ON t.id_Album = a.id
JOIN PerformerAlbum pa ON a.id = pa.album_id
JOIN Performer p ON pa.performer_id = p.id
WHERE p.name = 'Келвин'  
ORDER BY c.name;
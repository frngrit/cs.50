SELECT AVG(songs.energy) FROM songs, artists
WHERE artists.id = songs.artist_id
AND artists.name = "Drake";
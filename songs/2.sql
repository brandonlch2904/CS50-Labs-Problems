SELECT name FROM songs WHERE tempo IN (SELECT tempo FROM songs) ORDER BY tempo;
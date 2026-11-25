--
-- Tabellenstruktur für Tabelle `z25_v2`

-- Die Namen muessen mit 'xk' gebildet werden.
-- Ansonsten werden vom editor keine HRefs gesetzt

DROP TABLE IF EXISTS z25_v2;
DROP VIEW IF EXISTS  z25_v2;

CREATE VIEW z25_v2 AS 
SELECT 
        z25_file.ID     AS xkiFile,
        z25_movie.ID   AS xkiMovie,
        z25_movie.sTitleDE    AS sMovie_DE
FROM 
        z25_file, z25_movie, z25_z2_file2movie

WHERE   z25_z2_file2movie.xiFile   = z25_File.ID AND 
        z25_z2_file2movie.xiMovie  = z25_Movie.ID

ORDER BY 
       z25_z2_file2movie.xiFile;

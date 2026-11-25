--
-- Tabellenstruktur für Tabelle `z25_v1`

-- Die Namen muessen mit 'xk' gebildet werden.
-- Ansonsten werden vom editor keine HRefs gesetzt

DROP TABLE IF EXISTS z25_v1;
DROP VIEW IF EXISTS  z25_v1;

CREATE VIEW z25_v1 AS 
SELECT 
        z25_city.kcCity         AS xkcCity,
        z25_city.sCity          AS sCity,
        z25_country.kcCountry   AS xkcCountry,
        z25_country.sCountry    AS sCountry
FROM 
        z25_city, z25_country, z25_z1_city2country

WHERE   z25_z1_city2country.xcCity     = z25_city.kcCity  AND 
        z25_z1_city2country.xcCountry  = z25_country.kcCountry 

ORDER BY 
       z25_z1_city2country.xcCity;

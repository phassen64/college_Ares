-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Erstellungszeit: 01. Jan 2026 um 23:53
-- Server-Version: 10.4.32-MariaDB
-- PHP-Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Datenbank: `x16_athene`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `z25_award`
--

CREATE TABLE `z25_award` (
  `kcAward` char(8) NOT NULL COMMENT 'BaFT',
  `sAward` varchar(80) NOT NULL COMMENT 'Grammy Award',
  `sUrl` varchar(360) NOT NULL COMMENT '#https://de.wikipedia.org/wiki/Golden_Globe_Award#"'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `z25_award`
--

INSERT INTO `z25_award` (`kcAward`, `sAward`, `sUrl`) VALUES
('AA', '   Academy Awards', '   #https://de.wikipedia.org/wiki/Oscar#'),
('BaFT', ' BAFTA', '            #https://en.wikipedia.org/wiki/British_Academy_Film_Awards#'),
('Bamb', '                     Bambi', '#https://de.wikipedia.org/wiki/Bambi_(Auszeichnung)#'),
('CeSa', ' Ceasar', '           #https://de.wikipedia.org/wiki/C%C3%A9sar#'),
('Emmy', ' Emmy Award', '       #https://de.wikipedia.org/wiki/Emmy#'),
('EuFp', ' Europ?ischer Filmpreis', '   #https://de.wikipedia.org/wiki/Europ%C3%A4ischer_Filmpreis#'),
('GG', '   Golden Globe', '     #https://de.wikipedia.org/wiki/Golden_Globe_Award#'),
('Gmmy', ' Grammy Award', '     #https://de.wikipedia.org/wiki/Grammy_Awards#'),
('GoBa', ' Goldener Baer', '     #https://de.wikipedia.org/wiki/Goldener_B%C3%A4r#'),
('GoLe', ' Goldener Leopard', '  #https://de.wikipedia.org/wiki/Goldener_Leopard#'),
('GoLw', ' Goldener Loewe', '    #https://de.wikipedia.org/wiki/Goldener_L%C3%B6we#'),
('GoPa', ' Festival de Cannes', '#https://de.wikipedia.org/wiki/Internationale_Filmfestspiele_von_Cannes#'),
('SA', '   Saturn Award', '     #https://de.wikipedia.org/wiki/Saturn_Award#'),
('zHim', ' Goldene Himbeere', ' #https://de.wikipedia.org/wiki/Goldene_Himbeere#');

--
-- Indizes der exportierten Tabellen
--

--
-- Indizes für die Tabelle `z25_award`
--
ALTER TABLE `z25_award`
  ADD PRIMARY KEY (`kcAward`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

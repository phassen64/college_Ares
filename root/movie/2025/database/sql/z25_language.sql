-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Erstellungszeit: 01. Jan 2026 um 23:54
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
-- Tabellenstruktur für Tabelle `z25_language`
--

CREATE TABLE `z25_language` (
  `kcLanguage` char(2) NOT NULL COMMENT 'de',
  `sLanguage` varchar(80) NOT NULL COMMENT 'German',
  `sUrl` varchar(256) NOT NULL COMMENT '#https://de.wikipedia.org/wiki/Latein#'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `z25_language`
--

INSERT INTO `z25_language` (`kcLanguage`, `sLanguage`, `sUrl`) VALUES
('ar', 'Arabian', '#https://de.wikipedia.org/wiki/Arabische_Sprache#'),
('cs', 'Czech', '#https://de.wikipedia.org/wiki/Tschechische_Sprache#'),
('de', 'German', '#https://de.wikipedia.org/wiki/Deutsche_Sprache#'),
('en', 'English', '#https://de.wikipedia.org/wiki/Englische_Sprache#'),
('es', 'Spanish', '#https://de.wikipedia.org/wiki/Spanische_Sprache#'),
('fr', 'French', '#https://de.wikipedia.org/wiki/Franz%C3%B6sische_Sprache#'),
('in', 'Indisch', '#https://de.wikipedia.org/wiki/Sprachen_Indiens#'),
('it', 'Italian', '#https://de.wikipedia.org/wiki/Italienische_Sprache#'),
('ja', 'Japanese', '#https://de.wikipedia.org/wiki/Japanische_Sprache#'),
('la', 'Latin', '#https://de.wikipedia.org/wiki/Latein#'),
('pl', 'Polish', '#https://de.wikipedia.org/wiki/Polnische_Sprache#'),
('ps', 'Portuguese', '#https://de.wikipedia.org/wiki/Portugiesische_Sprache#'),
('ru', 'Russian', '#https://de.wikipedia.org/wiki/Russische_Sprache#'),
('tr', 'Turkish', '#https://de.wikipedia.org/wiki/T%C3%BCrkische_Sprache#'),
('us', 'AmEnglish', '#https://de.wikipedia.org/wiki/Amerikanisches_Englisch#'),
('zh', 'Chinese', '#https://de.wikipedia.org/wiki/Hochchinesisch#');

--
-- Indizes der exportierten Tabellen
--

--
-- Indizes für die Tabelle `z25_language`
--
ALTER TABLE `z25_language`
  ADD PRIMARY KEY (`kcLanguage`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

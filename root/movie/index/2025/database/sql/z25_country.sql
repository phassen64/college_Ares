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
-- Tabellenstruktur für Tabelle `z25_country`
--

CREATE TABLE `z25_country` (
  `kcCountry` char(3) NOT NULL COMMENT 'USA',
  `cDomain` char(2) NOT NULL COMMENT 'domain=us',
  `iPhone` tinyint(2) NOT NULL COMMENT 'de=49',
  `sCountry` varchar(30) NOT NULL COMMENT 'Espania',
  `sUrl` varchar(360) NOT NULL COMMENT '#https://de.wikipedia.org/wiki/Spanien#"'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `z25_country`
--

INSERT INTO `z25_country` (`kcCountry`, `cDomain`, `iPhone`, `sCountry`, `sUrl`) VALUES
('ARG', 'ar', 54, 'Argentina', '#https://de.wikipedia.org/wiki/Argentinien#'),
('ATA', 'at', 43, 'Austria', '#https://de.wikipedia.org/wiki/Austria#'),
('AUS', 'au', 61, 'Australia', '#https://de.wikipedia.org/wiki/Australien#'),
('BEL', 'be', 32, 'Belgien / EU', '#https://de.wikipedia.org/wiki/Belgien#'),
('BRA', 'br', 55, 'Brazil', '#https://de.wikipedia.org/wiki/Brasilien#'),
('CAN', 'ca', 1, 'Canada', '#https://de.wikipedia.org/wiki/Kanada#'),
('CHN', 'cn', 86, 'China', '#https://de.wikipedia.org/wiki/China#'),
('CHZ', 'ch', 41, 'Switzerland', '#https://de.wikipedia.org/wiki/Schweiz#'),
('CUB', 'cu', 53, 'Cuba', '#https://de.wikipedia.org/wiki/China#'),
('CZE', 'cz', 127, 'Czech Republic', '#https://de.wikipedia.org/wiki/Tschechien#'),
('DEU', 'de', 49, 'Germany', '#https://de.wikipedia.org/wiki/Deutschland#'),
('DNK', 'dk', 45, 'Denmark', '#https://de.wikipedia.org/wiki/D%C3%A4nemark#'),
('ESP', 'es', 34, 'Espania', '#https://de.wikipedia.org/wiki/Spanien#'),
('FRA', 'fr', 33, 'France', '#https://de.wikipedia.org/wiki/Frankreich#'),
('GBR', 'gb', 44, 'Great Britain & NI', '#https://de.wikipedia.org/wiki/Great_Britain#'),
('GRC', 'gr', 30, 'Greece', '#https://de.wikipedia.org/wiki/Griechenland#'),
('HUN', 'hu', 36, 'Ungarn', '#https://de.wikipedia.org/wiki/Ungarn#'),
('IDN', 'id', 62, 'Indonesia', '#https://de.wikipedia.org/wiki/Indonesien#'),
('IND', 'in', 91, 'India', '#https://de.wikipedia.org/wiki/Indien#'),
('IRL', 'ie', 127, 'Ireland', '#https://de.wikipedia.org/wiki/Irland#'),
('IRN', 'ir', 98, 'Iran', '#https://de.wikipedia.org/wiki/Iran#'),
('ISR', 'il', 127, 'Israel', '#https://de.wikipedia.org/wiki/Israel#'),
('ITA', 'it', 39, 'Italy', '#https://de.wikipedia.org/wiki/Italien#'),
('JPN', 'jp', 81, 'Japain', '#https://de.wikipedia.org/wiki/Japan#'),
('KOR', 'kr', 82, 'South Korea', '#https://de.wikipedia.org/wiki/S%C3%BCdkorea#'),
('MEX', 'mx', 52, 'Mexiko', '#https://de.wikipedia.org/wiki/Mexiko#'),
('MLT', 'mt', 127, 'Malta', '#https://de.wikipedia.org/wiki/Malta#'),
('MYS', 'my', 60, 'Malaysia', '#https://de.wikipedia.org/wiki/Niederlande#'),
('NET', 'nl', 31, 'Netherlands', '#https://de.wikipedia.org/wiki/Niederlande#'),
('NZL', 'nz', 64, 'New Zealand', '#https://de.wikipedia.org/wiki/Neuseeland#'),
('POL', 'pl', 48, 'Poland', '#https://de.wikipedia.org/wiki/Polen#'),
('PRT', 'pt', 127, 'Portugal', '#https://de.wikipedia.org/wiki/Portugal#'),
('ROU', 'ro', 40, 'Romania', '#https://de.wikipedia.org/wiki/Rum%C3%A4nien#'),
('RUS', 'ru', 7, 'Russia', '#https://de.wikipedia.org/wiki/Russland#'),
('SGP', 'sg', 65, 'Singapour', '#https://de.wikipedia.org/wiki/Singapur#'),
('SWE', 'se', 46, 'Schweden', '#https://de.wikipedia.org/wiki/Schweden#'),
('TAI', 'tw', 127, 'Taiwan', '#https://de.wikipedia.org/wiki/Republik_China_(Taiwan)#'),
('THA', 'th', 66, 'Thailand', '#https://de.wikipedia.org/wiki/Thailand#'),
('TUR', 'tr', 90, 'Turkey', '#https://de.wikipedia.org/wiki/T%C3%BCrkei#'),
('UK', 'uk', 44, 'United Kingdom', '#https://de.wikipedia.org/wiki/United_Kingdom#'),
('USA', 'us', 1, 'USA', '#https://de.wikipedia.org/wiki/USA#'),
('ZAF', 'za', 27, 'South Africa', '#https://de.wikipedia.org/wiki/S%C3%BCdafrika#');

--
-- Indizes der exportierten Tabellen
--

--
-- Indizes für die Tabelle `z25_country`
--
ALTER TABLE `z25_country`
  ADD PRIMARY KEY (`kcCountry`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

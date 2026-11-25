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
-- Tabellenstruktur für Tabelle `z25_city`
--

CREATE TABLE `z25_city` (
  `kcCity` char(3) NOT NULL COMMENT 'ATH',
  `sCity` varchar(30) NOT NULL COMMENT 'Athen',
  `sUrl` varchar(360) NOT NULL COMMENT '#https://de.wikipedia.org/wiki/Spanien#"'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `z25_city`
--

INSERT INTO `z25_city` (`kcCity`, `sCity`, `sUrl`) VALUES
('ATH', 'Athen', '#https://en.wikipedia.org/wiki/Athens#'),
('BAR', 'Barcelona', '#https://en.wikipedia.org/wiki/Barcelona#'),
('BER', 'Berlin', '#https://en.wikipedia.org/wiki/Berlin#'),
('BKK', 'Bangkok', '#https://en.wikipedia.org/wiki/Bangkok#'),
('CHI', 'Chicago', '#https://en.wikipedia.org/wiki/Chicago#'),
('CKG', 'Jakarta', '#https://en.wikipedia.org/wiki/Jakarta#'),
('HAM', 'Hamburg', '#https://en.wikipedia.org/wiki/Hamburg#'),
('HGK', 'Hong Kong', '#https://en.wikipedia.org/wiki/Hong_Kong#'),
('IST', 'Istanbul', '#https://en.wikipedia.org/wiki/Istanbul#'),
('JRS', 'Jerusalem', '#https://en.wikipedia.org/wiki/Istanbul#'),
('KUL', 'Kuala Lumpur', '#https://en.wikipedia.org/wiki/Kuala_Lumpur#'),
('LAS', 'Las Vegas', '#https://en.wikipedia.org/wiki/Las_Vegas#'),
('LAX', 'Los Angeles & Hollywood', '#https://en.wikipedia.org/wiki/Los_Angeles#'),
('LKG', 'Langkawi', '#https://en.wikipedia.org/wiki/Langkawi#'),
('LON', 'London', '#https://en.wikipedia.org/wiki/London#'),
('MAD', 'Madrid', '#https://en.wikipedia.org/wiki/Madrid#'),
('MAN', 'Manchester', '#https://en.wikipedia.org/wiki/Manchester#'),
('MEX', 'Mexiko City', '#https://en.wikipedia.org/wiki/Mexico_City#'),
('MIL', 'Milano', '#https://en.wikipedia.org/wiki/Milan#'),
('MOW', 'Moscow', '#https://en.wikipedia.org/wiki/Moscow#'),
('MUC', 'Muenchen', '#https://en.wikipedia.org/wiki/Munich#'),
('MUM', 'Mumbai', '#https://en.wikipedia.org/wiki/Mumbai#'),
('NYC', 'New York', '#https://en.wikipedia.org/wiki/New_York_City#'),
('PAR', 'Paris', '#https://en.wikipedia.org/wiki/Paris#'),
('PEK', 'Peking', '#https://en.wikipedia.org/wiki/Beijing#'),
('RIO', 'Rio de Janeiro', '#https://en.wikipedia.org/wiki/Rio_de_Janeiro#'),
('ROM', 'Rome', '#https://en.wikipedia.org/wiki/Rome#'),
('SAN', 'San Francisco', '#https://en.wikipedia.org/wiki/San_Francisco#'),
('SIN', 'Singapur City', '#https://en.wikipedia.org/wiki/Singapore#'),
('WAW', 'Warschau', '#https://de.wikipedia.org/wiki/Warschau#');

--
-- Indizes der exportierten Tabellen
--

--
-- Indizes für die Tabelle `z25_city`
--
ALTER TABLE `z25_city`
  ADD PRIMARY KEY (`kcCity`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

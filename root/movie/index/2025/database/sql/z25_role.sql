-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Erstellungszeit: 02. Jan 2026 um 00:02
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
-- Tabellenstruktur für Tabelle `z25_role`
--

CREATE TABLE `z25_role` (
  `kcRole` char(2) NOT NULL,
  `sRole` varchar(40) NOT NULL,
  `sUrl` varchar(256) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `z25_role`
--

INSERT INTO `z25_role` (`kcRole`, `sRole`, `sUrl`) VALUES
('ac', 'Actor', '#https://en.wikipedia.org/wiki/Actor#'),
('ci', 'Cinemator', '#https://en.wikipedia.org/wiki/Cinematographer#'),
('di', 'Director', '#https://en.wikipedia.org/wiki/Film_director#'),
('fe', 'Film Editor', '#https://en.wikipedia.org/wiki/Film_editing#'),
('mu', 'Film Music', '#https://en.wikipedia.org/wiki/Film_score#'),
('pr', 'Producer', '#https://en.wikipedia.org/wiki/Production_designer#'),
('sc', 'Screen Play', '#https://en.wikipedia.org/wiki/Screenplay#'),
('so', 'Song Performer', '#https://en.wikipedia.org/wiki/Wild_Women_Do#'),
('wr', 'Writer - Author', '#https://de.wikipedia.org/wiki/J._R._R._Tolkien#');

--
-- Indizes der exportierten Tabellen
--

--
-- Indizes für die Tabelle `z25_role`
--
ALTER TABLE `z25_role`
  ADD PRIMARY KEY (`kcRole`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

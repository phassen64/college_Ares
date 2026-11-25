-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Erstellungszeit: 02. Jan 2026 um 16:48
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
-- Datenbank: `x25_athene`
--

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `z25_genre`
--

CREATE TABLE `z25_genre` (
  `kcGenre` char(2) NOT NULL COMMENT 'fa',
  `sGenre` varchar(80) NOT NULL COMMENT 'Fantasy'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `z25_genre`
--

INSERT INTO `z25_genre` (`kcGenre`, `sGenre`) VALUES
('ac', 'Action'),
('ad', 'Adventure'),
('an', 'Animation'),
('bi', 'Biography'),
('bx', 'Boxer'),
('ca', 'Catastrophe'),
('cc', 'Comic'),
('ch', 'Christmas Movie'),
('co', 'Comedy'),
('do', 'Documentation'),
('dr', 'Drama'),
('er', 'Erotica'),
('fa', 'Fantasy'),
('ft', 'Fairy Tale'),
('ga', 'Gangster'),
('hc', 'Horror Comedy'),
('he', 'Heist Movie'),
('hi', 'History'),
('ho', 'Horror'),
('ju', 'Justice Movie'),
('le', 'Learning'),
('lo', 'Love'),
('me', 'Melodram'),
('mi', 'Military'),
('mo', 'Monster'),
('mu', 'Music Movie'),
('my', 'Mystery'),
('oc', 'Occult'),
('pa', 'Parody'),
('po', 'Politics'),
('py', 'Psycho'),
('rm', 'Road Movie'),
('sa', 'Satire'),
('sf', 'Scienes Fiction'),
('so', 'Soap Oper'),
('sp', 'Sport'),
('sx', 'SexFilm'),
('tc', 'Tragedy Comedy'),
('th', 'Thriller'),
('tr', 'Tragedy'),
('wc', 'Western Comedy'),
('we', 'Western');

--
-- Indizes der exportierten Tabellen
--

--
-- Indizes für die Tabelle `z25_genre`
--
ALTER TABLE `z25_genre`
  ADD PRIMARY KEY (`kcGenre`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

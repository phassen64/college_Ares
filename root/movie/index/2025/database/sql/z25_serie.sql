-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Erstellungszeit: 02. Jan 2026 um 00:18
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
-- Tabellenstruktur für Tabelle `z25_serie`
--

CREATE TABLE `z25_serie` (
  `kcSerie` varchar(20) NOT NULL COMMENT 'MIB',
  `sSerie` varchar(80) NOT NULL COMMENT 'Men in Black',
  `iYear` smallint(4) NOT NULL COMMENT '1997',
  `iSeason` tinyint(2) NOT NULL COMMENT '1',
  `iEpisode` smallint(4) NOT NULL COMMENT '3',
  `sUrl` varchar(256) NOT NULL COMMENT '"#https://de.wikipedia.org/wiki/Godzilla#"'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `z25_serie`
--

INSERT INTO `z25_serie` (`kcSerie`, `sSerie`, `iYear`, `iSeason`, `iEpisode`, `sUrl`) VALUES
('007', 'James Bond 007', 1962, 0, 22, '#https://de.wikipedia.org/wiki/James_Bond#'),
('Adams', 'The Adams Family', 1991, 0, 3, '#https://de.wikipedia.org/wiki/The_Addams_Family_(Begriffskl%C3%A4rung)##'),
('Alien', 'Alien', 1979, 0, 4, '#https://en.wikipedia.org/wiki/Alien_(film)#'),
('Arrow', 'Arrowverse', 2016, 9, 184, '#https://arrowverse.fandom.com/de/wiki/Liste_der_Crossoverepisoden#'),
('BBT', 'Big Bang Theory', 2007, 12, 279, '#https://en.wikipedia.org/wiki/The_Big_Bang_Theory#'),
('Bean', 'Mr. Bean', 1989, 3, 15, '#https://en.wikipedia.org/wiki/Mr._Bean#'),
('BTF', 'Back To the Future', 1985, 0, 3, '#https://de.wikipedia.org/wiki/Zur%C3%BCck_in_die_Zukunft_(Begriffskl%C3%A4rung)#'),
('DC', 'DC Universe', 1960, 0, 0, '#https://de.wikipedia.org/wiki/DC-Universum#'),
('DirtyHarry', 'Dirty Harry', 1971, 0, 5, '#https://de.wikipedia.org/wiki/Dirty_Harry#'),
('Dracula', 'Dracula', 1931, 0, 0, '#https://de.wikipedia.org/wiki/Dracula_(Roman)#'),
('FFtsy', 'Final Fantasy', 1987, 0, 0, '#https://de.wikipedia.org/wiki/Final_Fantasy#'),
('Flash', 'The Flash', 0, 6, 126, '#https://en.wikipedia.org/wiki/The_Flash_(2014_TV_series)#'),
('Ghost', 'Ghostbusters', 1984, 0, 3, '#https://de.wikipedia.org/wiki/Ghostbusters_(Begriffskl%C3%A4rung)#'),
('GodArmy', 'God\'s Army', 0, 0, 0, '#https://en.wikipedia.org/wiki/The_Prophecy#'),
('Godzilla', 'Godzilla', 0, 0, 0, '#https://de.wikipedia.org/wiki/Godzilla#'),
('Halloween', 'Halloween', 1978, 0, 7, '#https://de.wikipedia.org/wiki/Halloween#'),
('HarryPo', 'Harry Potter', 0, 9, 0, '#https://de.wikipedia.org/wiki/Harry_Potter#'),
('Indiana', 'Indiana Jones', 0, 0, 5, '#https://de.wikipedia.org/wiki/Indiana_Jones#'),
('Jeannie', 'I DreamOfJeannie', 1965, 3, 139, '#https://en.wikipedia.org/wiki/I_Dream_of_Jeannie#'),
('KGalacta', 'Kampfstern Galactica', 1978, 0, 3, '#https://de.wikipedia.org/wiki/Battlestar_Galactica_(Begriffskl%C3%A4rung)#'),
('KOQ', 'King Of Queens', 0, 10, 0, '#https://en.wikipedia.org/wiki/The_King_of_Queens#'),
('LeXX', 'LeXX', 1997, 0, 4, 'https://de.wikipedia.org/wiki/Lexx_%E2%80%93_The_Dark_Zone/Episodenliste#https://de.wikipedia.org/wiki/Lexx_%E2%80%93_The_Dark_Zone#'),
('LOTR', 'Lord Of the Rings', 2001, 0, 3, '#https://de.wikipedia.org/wiki/Der_Herr_der_Ringe_(Filmtrilogie)#'),
('Max', 'Mad Max', 1979, 0, 4, '#https://de.wikipedia.org/wiki/Mad_Max#'),
('MiB', 'Men in Black', 1997, 0, 3, '#https://de.wikipedia.org/wiki/Men_in_Black#'),
('MV', 'Marvel', 0, 0, 0, '#https://de.wikipedia.org/wiki/Marvel_Cinematic_Universe#'),
('NGun', 'Die Nackte Kanone', 0, 0, 3, '#https://de.wikipedia.org/wiki/Die_nackte_Pistole#'),
('Omen', 'Das Omen', 0, 0, 3, '#https://en.wikipedia.org/wiki/The_Omen#'),
('Pate', 'Der Pate', 0, 0, 3, '#https://de.wikipedia.org/wiki/Der_Pate#'),
('Pirat', 'Fluch der Karibik', 0, 0, 6, '#https://de.wikipedia.org/wiki/Pirates_of_the_Caribbean#'),
('Poltergeist', 'Poltergeist', 0, 0, 3, '#https://de.wikipedia.org/wiki/Poltergeist_(Begriffskl%C3%A4rung)#'),
('POTA', 'Planet der Affen', 0, 0, 2, '#https://de.wikipedia.org/wiki/Planet_der_Affen#'),
('Predator', 'Predator', 0, 0, 2, '#https://de.wikipedia.org/wiki/Predator_(Film)#'),
('Rambo', 'Rambo', 0, 0, 2, '#https://de.wikipedia.org/wiki/First_Blood_(Roman)#'),
('Riddick', 'Riddick', 0, 0, 4, '#https://en.wikipedia.org/wiki/Pitch_Black_(film)#'),
('Robocop', 'Robocop', 0, 0, 3, '#https://de.wikipedia.org/wiki/RoboCop#'),
('STrek', 'Star Trek', 0, 3, 79, '#https://en.wikipedia.org/wiki/Star_Trek:_The_Original_Series#'),
('SuperGirl', 'DC: Supergirl', 2015, 6, 91, '#https://en.wikipedia.org/wiki/Supergirl_(TV_series)#'),
('SWars', 'Star Wars', 1977, 0, 9, '#https://de.wikipedia.org/wiki/Star_Wars#'),
('Terminator', 'Terminator', 0, 0, 4, '#https://de.wikipedia.org/wiki/Terminator_(Film)#'),
('Transformer', 'Transformers', 0, 0, 4, '#https://de.wikipedia.org/wiki/Transformers#'),
('UWorld', 'Underworld', 0, 0, 4, '#https://de.wikipedia.org/wiki/Underworld_(Film)#');

--
-- Indizes der exportierten Tabellen
--

--
-- Indizes für die Tabelle `z25_serie`
--
ALTER TABLE `z25_serie`
  ADD PRIMARY KEY (`kcSerie`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Erstellungszeit: 02. Jan 2026 um 00:11
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
-- Tabellenstruktur für Tabelle `z25_depository`
--

CREATE TABLE `z25_depository` (
  `kiDepository` smallint(4) NOT NULL COMMENT '1100',
  `sLocation` varchar(40) NOT NULL COMMENT 'ReUpBack',
  `iMax` tinyint(3) NOT NULL COMMENT '30',
  `sRemark` varchar(80) NOT NULL COMMENT 'Regal-upper-backside'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `z25_depository`
--

INSERT INTO `z25_depository` (`kiDepository`, `sLocation`, `iMax`, `sRemark`) VALUES
(1100, 'ReUpBack', 30, 'Regal - upper -backside'),
(1200, 'ReUpFront', 30, 'Regal - oben -backside'),
(1300, 'ReDwBack', 30, 'Regal - unten - backside'),
(1400, 'ReDwFront', 30, 'Regal - oben - frontside'),
(4000, 'ReDwFront Temp', 20, 'Regal - oben - frontside - neue Disks'),
(5000, 'GenOriginal.A', 100, 'Ordner - original'),
(6000, 'GenOriginal.B', 80, 'Ordner Academy'),
(7000, 'GenMake', 100, 'Ordner DejaA 100-2xx'),
(8000, 'GenMake', 100, 'Ordner DejaB 300-4xx'),
(9000, 'GenDoc', 50, 'Ordner - klein Dokumentation');

--
-- Indizes der exportierten Tabellen
--

--
-- Indizes für die Tabelle `z25_depository`
--
ALTER TABLE `z25_depository`
  ADD PRIMARY KEY (`kiDepository`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

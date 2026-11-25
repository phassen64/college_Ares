-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Erstellungszeit: 02. Jan 2026 um 17:37
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
-- Tabellenstruktur für Tabelle `z25_currency`
--

CREATE TABLE `z25_currency` (
  `kcCurrency` char(3) NOT NULL COMMENT 'AUD',
  `cCurrency` varchar(8) DEFAULT NULL COMMENT 'R$',
  `sCurrency` varchar(80) NOT NULL COMMENT 'Rupiah INDONESIEN'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Daten für Tabelle `z25_currency`
--

INSERT INTO `z25_currency` (`kcCurrency`, `cCurrency`, `sCurrency`) VALUES
('AED', 'VAE', 'Dirham VAE'),
('ARS', '$', 'Peso'),
('AUD', '$', 'Dollar'),
('BRL', 'R$', 'Real BRA'),
('BYN', '-', 'Rubel'),
('CAD', '$', 'Dollar'),
('CHF', 'SFr', 'Franc'),
('CNY', 'Y', 'Renminbi Yuan'),
('CUC', '-', 'Peso Convertible'),
('CZK', 'K?', 'Tschech. Krone'),
('DKK', 'kr', 'Krone'),
('DOP', '-', 'Peso DomRep'),
('EGP', '-', 'Pfund Aegypt'),
('EUR', '@', 'Euro'),
('GBP', '£', 'Pfund'),
('HGK', '?', 'Hong Kong'),
('IDR', 'Rp', 'Rupiah'),
('ILS', 'NIS', 'ISR Schekel'),
('INR', '?', 'Rupie'),
('IRR', '?', 'Rial'),
('JPY', '¥', 'Yen'),
('KWD', 'KD', 'Dinar Kuwait'),
('LEU', 'RON', 'Rum.Leu'),
('LKR', 'Rs', 'Rupie'),
('MXV', 'Mex$', 'Unidad de Inversion'),
('MYR', 'RM', 'Ringgit'),
('NZD', '$', 'NZ Dollar'),
('PLN', 'Zl', 'Poln. Zloty'),
('RUB', '?', 'Rubel'),
('SEK', 'kr', 'Krone'),
('SGD', 'S$', 'Dollar'),
('THB', '?', 'Baht'),
('TRY', 'TRY', 'Lira'),
('USD', '$', 'Dollar'),
('VND', '?', 'Dong VIET'),
('Won', '?', 'SKR Won'),
('ZAR', 'R', 'Rand');

--
-- Indizes der exportierten Tabellen
--

--
-- Indizes für die Tabelle `z25_currency`
--
ALTER TABLE `z25_currency`
  ADD PRIMARY KEY (`kcCurrency`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

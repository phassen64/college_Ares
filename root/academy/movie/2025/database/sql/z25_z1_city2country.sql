-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 28, 2026 at 09:24 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `z25_zeus`
--

-- --------------------------------------------------------

--
-- Table structure for table `z25_z1_city2country`
--

CREATE TABLE `z25_z1_city2country` (
  `kiz1` int(2) DEFAULT NULL,
  `xcCity` char(3) DEFAULT NULL,
  `xcCountry` varchar(3) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

--
-- Dumping data for table `z25_z1_city2country`
--

INSERT INTO `z25_z1_city2country` (`kiz1`, `xcCity`, `xcCountry`) VALUES
(1, 'MEX', 'HUN'),
(2, 'BAR', 'ESP'),
(3, 'BER', 'DEU'),
(4, 'BKK', 'THA'),
(5, 'CHI', 'USA'),
(6, 'CKG', 'IDN'),
(7, 'HAM', 'DEU'),
(8, 'HGK', 'CHN'),
(9, 'IST', 'TUR'),
(10, 'JRS', 'ISR'),
(11, 'KUL', 'MYS'),
(12, 'LAS', 'USA'),
(13, 'LAX', 'USA'),
(14, 'LKG', 'MYS'),
(15, 'LON', 'UK'),
(16, 'MAD', 'ESP'),
(17, 'MAN', 'UK'),
(18, 'MEX', 'MEX'),
(19, 'MIL', 'ITA'),
(20, 'MOW', 'RUS'),
(21, 'MUC', 'DEU'),
(22, 'MUM', 'IND'),
(23, 'NYC', 'USA'),
(24, 'PAR', 'FRA'),
(25, 'PEK', 'CHN'),
(26, 'RIO', 'BRA'),
(27, 'ROM', 'ITA'),
(28, 'SAN', 'USA'),
(29, 'SIN', 'SGP'),
(30, 'WAW', 'POL'),
(31, 'BKK', 'CUB');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

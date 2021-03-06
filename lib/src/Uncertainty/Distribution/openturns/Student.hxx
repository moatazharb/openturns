//                                               -*- C++ -*-
/**
 *  @brief The Student distribution
 *
 *  Copyright 2005-2018 Airbus-EDF-IMACS-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OPENTURNS_STUDENT_HXX
#define OPENTURNS_STUDENT_HXX

#include "openturns/OTprivate.hxx"
#include "openturns/EllipticalDistribution.hxx"

BEGIN_NAMESPACE_OPENTURNS

/**
 * @class Student
 *
 * The Student distribution.
 */
class OT_API Student
  : public EllipticalDistribution
{

  CLASSNAME
public:

  /** Default constructor */
  explicit Student(const Scalar nu = 3.0,
                   const UnsignedInteger dimension = 1);

  /** Parameters constructor */
  Student(const Scalar nu,
          const Scalar mu,
          const Scalar sigma = 1.0);

  /** Parameters constructor */
  Student(const Scalar nu,
          const Point & mu,
          const Point & sigma,
          const CorrelationMatrix & R);


  /** Comparison operator */
  Bool operator ==(const Student & other) const;
protected:
  Bool equals(const DistributionImplementation & other) const;
public:

  /** String converter */
  String __repr__() const;
  String __str__(const String & offset = "") const;



  /* Interface inherited from Distribution */

  /** Virtual constructor */
  virtual Student * clone() const;

  /** Get one realization of the distribution */
  Point getRealization() const;

  /** Get the CDF of the distribution */
  using EllipticalDistribution::computeCDF;
  Scalar computeCDF(const Point & point) const;

  /** Get the probability content of an interval */
  Scalar computeProbability(const Interval & interval) const;

  /** Compute the entropy of the distribution */
  Scalar computeEntropy() const;

  /** Get the PDFGradient of the distribution */
  using EllipticalDistribution::computePDFGradient;
  Point computePDFGradient(const Point & point) const;

  /** Get the CDFGradient of the distribution */
  using EllipticalDistribution::computeCDFGradient;
  Point computeCDFGradient(const Point & point) const;

  /** Compute the radial distribution CDF */
  Scalar computeRadialDistributionCDF(const Scalar radius,
                                      const Bool tail = false) const;

  /** Compute the PDF of Xi | X1, ..., Xi-1. x = Xi, y = (X1,...,Xi-1) */
  using DistributionImplementation::computeConditionalPDF;
  Scalar computeConditionalPDF(const Scalar x, const Point & y) const;

  /** Compute the CDF of Xi | X1, ..., Xi-1. x = Xi, y = (X1,...,Xi-1) */
  using DistributionImplementation::computeConditionalCDF;
  Scalar computeConditionalCDF(const Scalar x, const Point & y) const;

  /** Compute the quantile of Xi | X1, ..., Xi-1, i.e. x such that CDF(x|y) = q with x = Xi, y = (X1,...,Xi-1) */
  using DistributionImplementation::computeConditionalQuantile;
  Scalar computeConditionalQuantile(const Scalar q, const Point & y) const;

  /** Get the i-th marginal distribution */
  Distribution getMarginal(const UnsignedInteger i) const;

  /** Get the distribution of the marginal distribution corresponding to indices dimensions */
  Distribution getMarginal(const Indices & indices) const;

  /** Get the mean of the distribution */
  Point getMean() const;

  /** Get the standard deviation of the distribution */
  Point getStandardDeviation() const;

  /** Get the skewness of the distribution */
  Point getSkewness() const;

  /** Get the kurtosis of the distribution */
  Point getKurtosis() const;

  /** Get the covariance of the distribution */
  CovarianceMatrix getCovariance() const;

  /** Get the raw moments of the standardized distribution */
  Point getStandardMoment(const UnsignedInteger n) const;

  /** Get the standard representative in the parametric family, associated with the standard moments */
  Distribution getStandardRepresentative() const;

  /** Parameters value and description accessor */
  PointWithDescriptionCollection getParametersCollection() const;
  using EllipticalDistribution::setParametersCollection;
  void setParametersCollection(const PointCollection & parametersCollection);

  /** Parameters value accessor */
  Point getParameter() const;
  void setParameter(const Point & parameter);

  /** Parameters description accessor */
  Description getParameterDescription() const;

  /** Tell if the distribution has independent copula */
  Bool hasIndependentCopula() const;

  /* Interface specific to Student */

  /** Nu accessor */
  void setNu(const Scalar nu);
  Scalar getNu() const;

  /** Mu accessor */
  void setMu(const Scalar mu);
  Scalar getMu() const;

  /** Compute the density generator of the ellipticalal generator, i.e.
   *  the function phi such that the density of the distribution can
   *  be written as p(x) = phi(t(x-mu)R^(-1)(x-mu))                      */
  Scalar computeDensityGenerator(const Scalar betaSquare) const;
  Scalar computeLogDensityGenerator(const Scalar betaSquare) const;

  /** Compute the derivative of the density generator */
  Scalar computeDensityGeneratorDerivative(const Scalar betaSquare) const;

  /** Compute the seconde derivative of the density generator */
  Scalar computeDensityGeneratorSecondDerivative(const Scalar betaSquare) const;

  /** Method save() stores the object through the StorageManager */
  void save(Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  void load(Advocate & adv);

protected:

private:

  /** Quantile computation for dimension=1 */
  Scalar computeScalarQuantile(const Scalar prob,
                               const Bool tail = false) const;

  /** The nu of the Student distribution */
  Scalar nu_;

  /** Specific normalization factor for the Student distribution */
  Scalar studentNormalizationFactor_;
}; /* class Student */


END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_STUDENT_HXX */

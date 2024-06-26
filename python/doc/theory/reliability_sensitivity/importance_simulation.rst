.. _importance_simulation:

Importance Simulation
---------------------

| Let us note
  :math:`\cD_f = \{\ux \in \Rset^{\inputDim} | \model(\ux) \leq 0\}`.
  The goal is to estimate the following probability:

  .. math::

     \begin{aligned}
         P_f & = \int_{\cD_f} f_{\uX}(\ux)d\ux\\
         & = \int_{\Rset^{n}} \mathbf{1}_{\{\model(\ux) \:\leq 0\: \}}f_{\uX}(\ux)d\ux\\
         & = \Prob {\{\model(\uX) \leq 0\}}
       \end{aligned}

| This is a sampling-based method. The main idea of the Importance
  Sampling method is to replace the initial probability distribution of
  the input variables by a more “efficient” one. “Efficient” means that
  more events will be counted in the failure domain :math:`\cD_f` and
  thus reduce the variance of the estimator of the probability of
  exceeding a threshold. Let :math:`\outputRV` be a random vector
  such that its probability density function
  :math:`f_{\outputRV} > 0` almost everywhere in the
  domain :math:`\cD_f`,

.. math::

   \begin{aligned}
       P_f &=& \int_{\Rset^{n}} \mathbf{1}_{\{\model(\ux) \leq 0 \}}f_{\uX}(\ux)d\ux\\
       &=& \int_{\Rset^{n}} \mathbf{1}_{\{\model(\ux) \leq 0 \}} \frac{f_{\uX}(\ux)}{f_{\outputRV}(\ux)}f_{\outputRV}(\ux)d\ux
     \end{aligned}

The estimator built by Importance Sampling method is:

.. math::

   \begin{aligned}
       \hat{P}_{f,IS}^N = \frac{1}{N}\sum_{i=1}^N \mathbf{1}_{\{\model(\outputRV_{\:i})) \leq 0 \}}\frac{f_{\uX}(\outputRV_{\:i})}{f_{\outputRV}(\outputRV_{\:i})}
     \end{aligned}

where:

-  :math:`N` is the total number of computations,

-  the random vectors :math:`\{\outputRV_i, i=1\hdots N\}` are
   independent, identically distributed and following the probability
   density function :math:`f_{\uY}`

**Confidence Intervals**

| With the notations,

  .. math::

     \begin{aligned}
         \mu_N &=& \frac{1}{N}\sum_{i=1}^N \mathbf{1}_{\{\model(\outputReal_{\:i})) \leq 0 \}}\frac{f_{\uX}(\outputReal_{\:i})}{f_{\outputRV}(\outputReal_{\:i})}\\
         \sigma_N^2 &=& \frac{1}{N}\sum_{i=1}^N (\mathbf{1}_{\{\model(\outputReal_i)) \leq 0 \}}\frac{f_{\uX}(\outputReal_{\:i})}{f_{\outputRV}(\outputReal_{\:i})} - \mu_N)^2
       \end{aligned}

The asymptotic confidence interval of order :math:`1-\alpha` associated
to the estimator :math:`P_{f,IS}^N` is

.. math::

   \begin{aligned}
       [ \mu_N - \frac{q_{1-\alpha / 2} . \sigma_N}{\sqrt{N}} \: ; \: \mu_N + \frac{q_{1-\alpha / 2} . \sigma_N}{\sqrt{N}} ]
     \end{aligned}

where :math:`q_{1-\alpha /2}` is the :math:`1-\alpha / 2` quantile from
the standard distribution :math:`\cN(0,1)`.

This method could also be found under the name “Strategic Sampling”,
“Weighted Sampling” or “Biased Sampling” (even if this estimator is
not biased as it gives exactly the same result).


.. topic:: API:

    - See :class:`~openturns.ProbabilitySimulationAlgorithm`
    - See :class:`~openturns.ImportanceSamplingExperiment`


.. topic:: Examples:

    - See :doc:`/auto_reliability_sensitivity/reliability/plot_estimate_probability_importance_sampling`


.. topic:: References:

    - W.G. Cochran. Sampling Techniques. John Wiley and Sons, 1977.
    - M.H. Kalos et P.A. Monte Carlo Methods, volume I: Basics. John Wiley and Sons, 1986.
    - R.Y. Rubinstein. Simulation and the Monte Carlo Method. John Wiley and Sons, 1981.

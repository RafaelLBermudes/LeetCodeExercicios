# Rafael Lopes Bermudes
# LeetCode 775 - Inversoes Globais e Locais ( Global and Local Inversions )

	Voce recebe um array de inteiros nums de comprimento n que representa
	uma permutacao de todos os inteiros no intervalo [0, n - 1].

	O numero de inversoes GLOBAIS e o numero de pares ( i, j ) diferentes
	onde:

		0 <= i < j < n  e  nums[i] > nums[j]

	O numero de inversoes LOCAIS e o numero de indices i onde:

		0 <= i < n - 1  e  nums[i] > nums[i + 1]

	Retorne true se o numero de inversoes globais for igual ao numero de
	inversoes locais.

	Exemplo 1:

		Entrada: nums = [1,0,2]
		Saida: true
		Explicacao: ha 1 inversao global e 1 inversao local.

	Exemplo 2:

		Entrada: nums = [1,2,0]
		Saida: false
		Explicacao: ha 2 inversoes globais e 1 inversao local.

	Restricoes:

		n == nums.length
		1 <= n <= 10^5
		0 <= nums[i] < n
		Todos os inteiros de nums sao distintos
		nums e uma permutacao de todos os numeros no intervalo [0, n - 1]

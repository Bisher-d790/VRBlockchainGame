package com.academy.contracts;

import java.math.BigInteger;
import java.util.Arrays;
import java.util.List;
import java.util.concurrent.Callable;
import org.web3j.abi.TypeReference;
import org.web3j.abi.datatypes.Address;
import org.web3j.abi.datatypes.Bool;
import org.web3j.abi.datatypes.DynamicArray;
import org.web3j.abi.datatypes.DynamicBytes;
import org.web3j.abi.datatypes.Function;
import org.web3j.abi.datatypes.Type;
import org.web3j.abi.datatypes.Utf8String;
import org.web3j.abi.datatypes.generated.Bytes1;
import org.web3j.abi.datatypes.generated.Int256;
import org.web3j.abi.datatypes.generated.Int8;
import org.web3j.abi.datatypes.generated.Uint256;
import org.web3j.abi.datatypes.generated.Uint8;
import org.web3j.crypto.Credentials;
import org.web3j.protocol.Web3j;
import org.web3j.protocol.core.RemoteCall;
import org.web3j.tx.Contract;
import org.web3j.tx.TransactionManager;
import org.web3j.tx.gas.ContractGasProvider;

/**
 * <p>Auto generated code.
 * <p><strong>Do not modify!</strong>
 * <p>Please use the <a href="https://docs.web3j.io/command_line.html">web3j command line tools</a>,
 * or the org.web3j.codegen.SolidityFunctionWrapperGenerator in the 
 * <a href="https://github.com/web3j/web3j/tree/master/codegen">codegen module</a> to update.
 *
 * <p>Generated with web3j version 4.1.0.
 */
public class MethodParamsTester extends Contract {
    private static final String BINARY = "608060405234801561001057600080fd5b50610bbf806100206000396000f3006080604052600436106100cf5763ffffffff7c010000000000000000000000000000000000000000000000000000000060003504166306a2d5ac81146100d4578063109cdfcd1461010a57806322e51100146100d457806352b696e4146101325780636a57db531461015a578063788e29f814610187578063816fcff1146101a257806383d19ab4146101ca57806392bd51fc146101f257806393bb626814610187578063985c4c4214610212578063ac59c9601461023a578063cfae321714610262578063f225190714610277575b600080fd5b3480156100e057600080fd5b506100f46100ef366004610815565b61029f565b6040516101019190610a4c565b60405180910390f35b34801561011657600080fd5b506101256100ef36600461073a565b6040516101019190610a0e565b34801561013e57600080fd5b5061014d6100ef3660046107a4565b6040516101019190610a1f565b34801561016657600080fd5b5061017a61017536600461076f565b6102a6565b6040516101019190610a3b565b34801561019357600080fd5b5061017a6100ef3660046107e0565b3480156101ae57600080fd5b506101bd6100ef366004610705565b60405161010191906109fd565b3480156101d657600080fd5b506101e56100ef366004610898565b6040516101019190610a5a565b3480156101fe57600080fd5b5061017a61020d366004610833565b610477565b34801561021e57600080fd5b5061022d6100ef3660046108b6565b6040516101019190610a68565b34801561024657600080fd5b506102556100ef3660046106df565b60405161010191906109e9565b34801561026e57600080fd5b5061017a6104c5565b34801561028357600080fd5b506102926100ef3660046107c2565b6040516101019190610a2d565b805b919050565b604080517f413100000000000000000000000000000000000000000000000000000000000081529051908190036002019020815160609190839060009081106102eb57fe5b906020019060200201516040518082805190602001908083835b602083106103245780518252601f199092019160209182019101610305565b6001836020036101000a03801982511681845116808217855250505050505090500191505060405180910390206000191614156103e95750604080517f746573743100000000000000000000000000000000000000000000000000000060208201527f746573743200000000000000000000000000000000000000000000000000000060258201527f7465737433000000000000000000000000000000000000000000000000000000602a8201528151600f818303018152602f9091019091526102a1565b50604080517f536f6d657468696e67000000000000000000000000000000000000000000000060208201527f57656e740000000000000000000000000000000000000000000000000000000060298201527f57726f6e67000000000000000000000000000000000000000000000000000000602d8201528151601281830301815260329091019091526102a1565b6060828413156104885750806104be565b5060408051808201909152601981527f696e70757456616c756532203c20696e70757456616c7565310000000000000060208201525b9392505050565b60408051808201909152601a81527f48656c6c6f20457468657265756d20426c6f636b636861696e21000000000000602082015290565b60006104be8235610af0565b6000601f8201831361051957600080fd5b813561052c61052782610a9d565b610a76565b9150818183526020840193506020810190508385602084028201111561055157600080fd5b60005b8381101561057d57816105678882610654565b8452506020928301929190910190600101610554565b5050505092915050565b6000601f8201831361059857600080fd5b81356105a661052782610a9d565b915081818352602084019350602081019050838560208402820111156105cb57600080fd5b60005b8381101561057d57816105e188826106bb565b84525060209283019291909101906001016105ce565b6000601f8201831361060857600080fd5b813561061661052782610a9d565b81815260209384019390925082018360005b8381101561057d578135860161063e888261066c565b8452506020928301929190910190600101610628565b60006104be8235610b09565b60006104be8235610b0e565b6000601f8201831361067d57600080fd5b813561068b61052782610abe565b915080825260208301602083018583830111156106a757600080fd5b6106b2838284610b3f565b50505092915050565b60006104be823561029f565b60006104be8235610b33565b60006104be8235610b39565b6000602082840312156106f157600080fd5b60006106fd84846104fc565b949350505050565b60006020828403121561071757600080fd5b813567ffffffffffffffff81111561072e57600080fd5b6106fd84828501610508565b60006020828403121561074c57600080fd5b813567ffffffffffffffff81111561076357600080fd5b6106fd84828501610587565b60006020828403121561078157600080fd5b813567ffffffffffffffff81111561079857600080fd5b6106fd848285016105f7565b6000602082840312156107b657600080fd5b60006106fd8484610654565b6000602082840312156107d457600080fd5b60006106fd8484610660565b6000602082840312156107f257600080fd5b813567ffffffffffffffff81111561080957600080fd5b6106fd8482850161066c565b60006020828403121561082757600080fd5b60006106fd84846106bb565b60008060006060848603121561084857600080fd5b600061085486866106bb565b9350506020610865868287016106bb565b925050604084013567ffffffffffffffff81111561088257600080fd5b61088e8682870161066c565b9150509250925092565b6000602082840312156108aa57600080fd5b60006106fd84846106c7565b6000602082840312156108c857600080fd5b60006106fd84846106d3565b6108dd81610af0565b82525050565b60006108ee82610aec565b80845260208401935061090083610ae6565b60005b8281101561093057610916868351610987565b61091f82610ae6565b602096909601959150600101610903565b5093949350505050565b600061094582610aec565b80845260208401935061095783610ae6565b60005b828110156109305761096d8683516109ce565b61097682610ae6565b60209690960195915060010161095a565b6108dd81610b09565b6108dd81610b0e565b60006109a482610aec565b8084526109b8816020860160208601610b4b565b6109c181610b7b565b9093016020019392505050565b6108dd8161029f565b6108dd81610b33565b6108dd81610b39565b602081016109f782846108d4565b92915050565b602080825281016104be81846108e3565b602080825281016104be818461093a565b602081016109f78284610987565b602081016109f78284610990565b602080825281016104be8184610999565b602081016109f782846109ce565b602081016109f782846109d7565b602081016109f782846109e0565b60405181810167ffffffffffffffff81118282101715610a9557600080fd5b604052919050565b600067ffffffffffffffff821115610ab457600080fd5b5060209081020190565b600067ffffffffffffffff821115610ad557600080fd5b506020601f91909101601f19160190565b60200190565b5190565b73ffffffffffffffffffffffffffffffffffffffff1690565b151590565b7fff000000000000000000000000000000000000000000000000000000000000001690565b60000b90565b60ff1690565b82818337506000910152565b60005b83811015610b66578181015183820152602001610b4e565b83811115610b75576000848401525b50505050565b601f01601f1916905600a265627a7a723058200c7b6c69d8847377dc3b7d56b79ff2e48674dbded0a579273ee63050024ec49f6c6578706572696d656e74616cf50037";

    public static final String FUNC_INTTEST = "intTest";

    public static final String FUNC_INTARRAYTEST = "intArrayTest";

    public static final String FUNC_UINTTEST = "uintTest";

    public static final String FUNC_BOOLTEST = "boolTest";

    public static final String FUNC_STRINGARRAYTEST = "stringArrayTest";

    public static final String FUNC_STRINGTEST = "stringTest";

    public static final String FUNC_BOOLARRAYTEST = "boolArrayTest";

    public static final String FUNC_INT8TEST = "int8Test";

    public static final String FUNC_MULTIPLEPARAMSTEST = "multipleParamsTest";

    public static final String FUNC_BYTESARRAYTEST = "bytesArrayTest";

    public static final String FUNC_UINT8TEST = "uint8Test";

    public static final String FUNC_ADDRESSTEST = "addressTest";

    public static final String FUNC_GREET = "greet";

    public static final String FUNC_BYTETEST = "byteTest";

    @Deprecated
    protected MethodParamsTester(String contractAddress, Web3j web3j, Credentials credentials, BigInteger gasPrice, BigInteger gasLimit) {
        super(BINARY, contractAddress, web3j, credentials, gasPrice, gasLimit);
    }

    protected MethodParamsTester(String contractAddress, Web3j web3j, Credentials credentials, ContractGasProvider contractGasProvider) {
        super(BINARY, contractAddress, web3j, credentials, contractGasProvider);
    }

    @Deprecated
    protected MethodParamsTester(String contractAddress, Web3j web3j, TransactionManager transactionManager, BigInteger gasPrice, BigInteger gasLimit) {
        super(BINARY, contractAddress, web3j, transactionManager, gasPrice, gasLimit);
    }

    protected MethodParamsTester(String contractAddress, Web3j web3j, TransactionManager transactionManager, ContractGasProvider contractGasProvider) {
        super(BINARY, contractAddress, web3j, transactionManager, contractGasProvider);
    }

    public RemoteCall<BigInteger> intTest(BigInteger inputValue) {
        final Function function = new Function(FUNC_INTTEST, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Int256(inputValue)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Int256>() {}));
        return executeRemoteCallSingleValueReturn(function, BigInteger.class);
    }

    public RemoteCall<List> intArrayTest(List<BigInteger> inputValue) {
        final Function function = new Function(FUNC_INTARRAYTEST, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.DynamicArray<org.web3j.abi.datatypes.generated.Int256>(
                        org.web3j.abi.Utils.typeMap(inputValue, org.web3j.abi.datatypes.generated.Int256.class))), 
                Arrays.<TypeReference<?>>asList(new TypeReference<DynamicArray<Int256>>() {}));
        return new RemoteCall<List>(
                new Callable<List>() {
                    @Override
                    @SuppressWarnings("unchecked")
                    public List call() throws Exception {
                        List<Type> result = (List<Type>) executeCallSingleValueReturn(function, List.class);
                        return convertToNative(result);
                    }
                });
    }

    public RemoteCall<BigInteger> uintTest(BigInteger inputValue) {
        final Function function = new Function(FUNC_UINTTEST, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(inputValue)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Uint256>() {}));
        return executeRemoteCallSingleValueReturn(function, BigInteger.class);
    }

    public RemoteCall<Boolean> boolTest(Boolean inputValue) {
        final Function function = new Function(FUNC_BOOLTEST, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Bool(inputValue)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Bool>() {}));
        return executeRemoteCallSingleValueReturn(function, Boolean.class);
    }

    public RemoteCall<String> stringArrayTest(List<String> inputValue) {
        final Function function = new Function(FUNC_STRINGARRAYTEST, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.DynamicArray<org.web3j.abi.datatypes.Utf8String>(
                        org.web3j.abi.Utils.typeMap(inputValue, org.web3j.abi.datatypes.Utf8String.class))), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Utf8String>() {}));
        return executeRemoteCallSingleValueReturn(function, String.class);
    }

    public RemoteCall<String> stringTest(String inputValue) {
        final Function function = new Function(FUNC_STRINGTEST, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Utf8String(inputValue)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Utf8String>() {}));
        return executeRemoteCallSingleValueReturn(function, String.class);
    }

    public RemoteCall<List> boolArrayTest(List<Boolean> inputValue) {
        final Function function = new Function(FUNC_BOOLARRAYTEST, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.DynamicArray<org.web3j.abi.datatypes.Bool>(
                        org.web3j.abi.Utils.typeMap(inputValue, org.web3j.abi.datatypes.Bool.class))), 
                Arrays.<TypeReference<?>>asList(new TypeReference<DynamicArray<Bool>>() {}));
        return new RemoteCall<List>(
                new Callable<List>() {
                    @Override
                    @SuppressWarnings("unchecked")
                    public List call() throws Exception {
                        List<Type> result = (List<Type>) executeCallSingleValueReturn(function, List.class);
                        return convertToNative(result);
                    }
                });
    }

    public RemoteCall<BigInteger> int8Test(BigInteger inputValue) {
        final Function function = new Function(FUNC_INT8TEST, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Int8(inputValue)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Int8>() {}));
        return executeRemoteCallSingleValueReturn(function, BigInteger.class);
    }

    public RemoteCall<String> multipleParamsTest(BigInteger inputValue1, BigInteger inputValue2, String inputValue3) {
        final Function function = new Function(FUNC_MULTIPLEPARAMSTEST, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Int256(inputValue1), 
                new org.web3j.abi.datatypes.generated.Int256(inputValue2), 
                new org.web3j.abi.datatypes.Utf8String(inputValue3)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Utf8String>() {}));
        return executeRemoteCallSingleValueReturn(function, String.class);
    }

    public RemoteCall<byte[]> bytesArrayTest(byte[] inputValue) {
        final Function function = new Function(FUNC_BYTESARRAYTEST, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.DynamicBytes(inputValue)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<DynamicBytes>() {}));
        return executeRemoteCallSingleValueReturn(function, byte[].class);
    }

    public RemoteCall<BigInteger> uint8Test(BigInteger inputValue) {
        final Function function = new Function(FUNC_UINT8TEST, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint8(inputValue)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Uint8>() {}));
        return executeRemoteCallSingleValueReturn(function, BigInteger.class);
    }

    public RemoteCall<String> addressTest(String inputValue) {
        final Function function = new Function(FUNC_ADDRESSTEST, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(inputValue)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Address>() {}));
        return executeRemoteCallSingleValueReturn(function, String.class);
    }

    public RemoteCall<String> greet() {
        final Function function = new Function(FUNC_GREET, 
                Arrays.<Type>asList(), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Utf8String>() {}));
        return executeRemoteCallSingleValueReturn(function, String.class);
    }

    public RemoteCall<byte[]> byteTest(byte[] inputValue) {
        final Function function = new Function(FUNC_BYTETEST, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Bytes1(inputValue)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Bytes1>() {}));
        return executeRemoteCallSingleValueReturn(function, byte[].class);
    }

    @Deprecated
    public static MethodParamsTester load(String contractAddress, Web3j web3j, Credentials credentials, BigInteger gasPrice, BigInteger gasLimit) {
        return new MethodParamsTester(contractAddress, web3j, credentials, gasPrice, gasLimit);
    }

    @Deprecated
    public static MethodParamsTester load(String contractAddress, Web3j web3j, TransactionManager transactionManager, BigInteger gasPrice, BigInteger gasLimit) {
        return new MethodParamsTester(contractAddress, web3j, transactionManager, gasPrice, gasLimit);
    }

    public static MethodParamsTester load(String contractAddress, Web3j web3j, Credentials credentials, ContractGasProvider contractGasProvider) {
        return new MethodParamsTester(contractAddress, web3j, credentials, contractGasProvider);
    }

    public static MethodParamsTester load(String contractAddress, Web3j web3j, TransactionManager transactionManager, ContractGasProvider contractGasProvider) {
        return new MethodParamsTester(contractAddress, web3j, transactionManager, contractGasProvider);
    }

    public static RemoteCall<MethodParamsTester> deploy(Web3j web3j, Credentials credentials, ContractGasProvider contractGasProvider) {
        return deployRemoteCall(MethodParamsTester.class, web3j, credentials, contractGasProvider, BINARY, "");
    }

    @Deprecated
    public static RemoteCall<MethodParamsTester> deploy(Web3j web3j, Credentials credentials, BigInteger gasPrice, BigInteger gasLimit) {
        return deployRemoteCall(MethodParamsTester.class, web3j, credentials, gasPrice, gasLimit, BINARY, "");
    }

    public static RemoteCall<MethodParamsTester> deploy(Web3j web3j, TransactionManager transactionManager, ContractGasProvider contractGasProvider) {
        return deployRemoteCall(MethodParamsTester.class, web3j, transactionManager, contractGasProvider, BINARY, "");
    }

    @Deprecated
    public static RemoteCall<MethodParamsTester> deploy(Web3j web3j, TransactionManager transactionManager, BigInteger gasPrice, BigInteger gasLimit) {
        return deployRemoteCall(MethodParamsTester.class, web3j, transactionManager, gasPrice, gasLimit, BINARY, "");
    }
}
